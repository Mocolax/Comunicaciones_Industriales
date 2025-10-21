#include <SoftwareSerial.h>

// ========================= CONFIGURACIÓN =========================
// Elige UN solo modo a la vez poniendo 1 y los otros en 0
#define MODE_SIMPLEX_MASTER   1
#define MODE_SIMPLEX_SLAVE    0
#define MODE_FULL_DUPLEX_PEER 0

// Paquetes y temporización (similar a performance_test.py)
const unsigned NUM_PACKETS   = 100;
const unsigned SEND_GAP_MS   = 10;     // 10 ms entre envíos
const unsigned ACK_TIMEOUT_MS = 20;    // tiempo máximo para esperar ACK (ajusta según baudios y cable)

// RS485 - Simplex
const uint8_t PIN_RX_SX   = 2;  // Arduino lee aquí
const uint8_t PIN_TX_SX   = 3;  // Arduino envía aquí
const uint8_t PIN_DE_RE_SX = 4; // DE y /RE puenteados (Simplex)

// RS485 - Full-Duplex (dos módulos)
const uint8_t PIN_RX_FD   = 2;  // RX dedicado (desde módulo RX)
const uint8_t PIN_TX_FD   = 3;  // TX dedicado (hacia módulo TX)
const uint8_t PIN_DE_TX   = 4;  // DE del módulo TX (HIGH siempre)
const uint8_t PIN_RE_RX   = 5;  // /RE del módulo RX (LOW siempre)

// UARTs por modo
#if MODE_SIMPLEX_MASTER || MODE_SIMPLEX_SLAVE
SoftwareSerial rs485(PIN_RX_SX, PIN_TX_SX); // RX, TX
#endif

#if MODE_FULL_DUPLEX_PEER
// Dos instancias: una para TX (solo escribir), otra para RX (solo escuchar).
// En SoftwareSerial la que "escucha" es la que se hace listen(). Aquí escuchamos en rxBus.
SoftwareSerial rxBus(PIN_RX_FD, PIN_TX_FD); // usamos solo RX de esta instancia
// Para transmitir usamos print/println sobre rxBus también (TX_FD), pero no la ponemos en listen() nunca.
#endif

// ========================= PROTOCOLO =========================
// Trama TX: "SEQ,CHK\n"  con CHK = (seq & 0xFF) ^ 0xA5
// Respuesta ACK: "A:SEQ\n"
// Respuesta NAK: "N:SEQ\n"

static inline uint8_t makeChk(uint32_t seq) {
  return (uint8_t)((seq & 0xFF) ^ 0xA5);
}

void sendFrame_Stream(Print &port, uint32_t seq) {
  uint8_t chk = makeChk(seq);
  port.print(seq);
  port.print(",");
  port.println(chk);
}

bool parseFrame(const String &line, uint32_t &seqOut) {
  // Espera "seq,chk"
  int comma = line.indexOf(',');
  if (comma <= 0) return false;
  String sseq = line.substring(0, comma);
  String schak = line.substring(comma + 1);
  sseq.trim(); schak.trim();
  for (unsigned i = 0; i < sseq.length(); ++i) if (!isDigit(sseq[i])) return false;
  for (unsigned i = 0; i < schak.length(); ++i) if (!isDigit(schak[i])) return false;
  uint32_t seq = (uint32_t)sseq.toInt();
  uint8_t  chk = (uint8_t)schak.toInt();
  if (chk != makeChk(seq)) return false;
  seqOut = seq;
  return true;
}

bool parseAck(const String &line, uint32_t &seqOut, bool &isAck) {
  // "A:seq" o "N:seq"
  if (line.length() < 3) return false;
  char t = line.charAt(0);
  if (t != 'A' && t != 'N') return false;
  if (line.charAt(1) != ':') return false;
  String sseq = line.substring(2);
  sseq.trim();
  for (unsigned i = 0; i < sseq.length(); ++i) if (!isDigit(sseq[i])) return false;
  seqOut = (uint32_t)sseq.toInt();
  isAck = (t == 'A');
  return true;
}

void sendAck(Stream &port, uint32_t seq, bool ack) {
  if (ack) { port.print("A:"); }
  else     { port.print("N:"); }
  port.println(seq);
}

// ========================= MÉTRICAS =========================
unsigned long t_start_ms = 0;
unsigned long t_end_ms   = 0;

unsigned long tx_successes = 0;
unsigned long rx_valid     = 0;
unsigned long rx_errors    = 0;

// ========================= UTILIDADES =========================
void setSimplexTX(bool on) {
#if MODE_SIMPLEX_MASTER || MODE_SIMPLEX_SLAVE
  digitalWrite(PIN_DE_RE_SX, on ? HIGH : LOW);
#endif
}

void beginBuses() {
#if MODE_SIMPLEX_MASTER || MODE_SIMPLEX_SLAVE
  pinMode(PIN_DE_RE_SX, OUTPUT);
  setSimplexTX(false); // recibir por defecto
  rs485.begin(38400);
#endif

#if MODE_FULL_DUPLEX_PEER
  pinMode(PIN_DE_TX, OUTPUT);
  pinMode(PIN_RE_RX, OUTPUT);
  digitalWrite(PIN_DE_TX, HIGH); // Habilitar TX permanente
  digitalWrite(PIN_RE_RX, LOW);  // Habilitar RX permanente
  rxBus.begin(38400);
  rxBus.listen(); // escuchar en RX dedicado
#endif
}

// Lee una línea (hasta '\n') con timeout en ms desde un Stream
bool readLineWithTimeout(Stream &s, String &out, unsigned timeout_ms) {
  unsigned long t0 = millis();
  out = "";
  while (millis() - t0 < timeout_ms) {
    while (s.available()) {
      char c = (char)s.read();
      if (c == '\n') {
        out.trim();
        return true;
      }
      out += c;
    }
  }
  out.trim();
  return (out.length() > 0); // si salió por timeout pero con algo, se devuelve true
}

// ========================= ROLES =========================
#if MODE_SIMPLEX_MASTER
void runSimplexMaster() {
  Serial.println(F("[Simplex Master] Benchmark iniciando..."));
  delay(200);

  t_start_ms = millis();
  for (uint32_t i = 0; i < NUM_PACKETS; ++i) {
    // Enviar
    setSimplexTX(true);
    delayMicroseconds(40);
    sendFrame_Stream(rs485, i);
    delayMicroseconds(40);
    setSimplexTX(false);

    // Esperar ACK
    String line;
    uint32_t seqAck = 0; bool isAck = false;
    if (readLineWithTimeout(rs485, line, ACK_TIMEOUT_MS) && parseAck(line, seqAck, isAck) && isAck && seqAck == i) {
      tx_successes++;
    } else {
      // No ACK o NAK o mismatch -> fallo
    }

    delay(SEND_GAP_MS);
  }
  t_end_ms = millis();

  // Métricas
  float total_s = (t_end_ms - t_start_ms) / 1000.0f;
  float succ_rate = 100.0f * (float)tx_successes / (float)NUM_PACKETS;
  float thr = (float)NUM_PACKETS / total_s;

  Serial.println(F("----- RESULTADOS Simplex -----"));
  Serial.print(F("Paquetes: ")); Serial.println(NUM_PACKETS);
  Serial.print(F("Tiempo: "));   Serial.print(total_s, 2); Serial.println(F(" s"));
  Serial.print(F("Tasa éxito: ")); Serial.print(succ_rate, 1); Serial.println(F(" %"));
  Serial.print(F("Throughput: ")); Serial.print(thr, 1); Serial.println(F(" pkt/s"));
  Serial.println(F("-----------------------------"));
}
#endif

#if MODE_SIMPLEX_SLAVE
void runSimplexSlave() {
  Serial.println(F("[Simplex Slave] Esperando paquetes..."));
  delay(200);

  unsigned long received = 0;
  while (received < NUM_PACKETS) {
    if (rs485.available()) {
      String line = rs485.readStringUntil('\n');
      line.trim();
      if (line.length() == 0) continue;

      uint32_t seq = 0;
      bool ok = parseFrame(line, seq);
      // Responder ACK/NAK
      setSimplexTX(true);
      delayMicroseconds(40);
      sendAck(rs485, seq, ok);
      delayMicroseconds(40);
      setSimplexTX(false);

      if (ok) rx_valid++;
      else rx_errors++;
      received++;
    }
  }

  // Reporte local (solo informativo)
  Serial.println(F("----- RX Simplex (Slave) -----"));
  Serial.print(F("Válidos: ")); Serial.println(rx_valid);
  Serial.print(F("Errores: ")); Serial.println(rx_errors);
  Serial.println(F("------------------------------"));
}
#endif

#if MODE_FULL_DUPLEX_PEER
void runFullDuplexPeer() {
  Serial.println(F("[Full-Duplex Peer] Benchmark iniciando..."));
  delay(200);

  t_start_ms = millis();

  uint32_t nextToSend = 0;
  unsigned long lastSend = 0;

  // Para confirmar éxito TX, contamos ACKs *de mis SEQ*
  // Mi identidad simple: OFFSET configurable si quieres diferenciar pares.
  const uint32_t SEQ_OFFSET = 0; // cámbialo a 100000 en el otro peer si quieres evitar colisiones lógicas
  uint32_t myAcked = 0;

  while ( (millis() - t_start_ms) < 600000UL ) { // tope duro seguridad 10 min
    unsigned long now = millis();

    // Envío con gap
    if (nextToSend < NUM_PACKETS && (now - lastSend) >= SEND_GAP_MS) {
      uint32_t seq = SEQ_OFFSET + nextToSend;
      // Transmitimos por el bus TX dedicado (rxBus usa TX_FD como salida)
      rxBus.print(seq);
      rxBus.print(",");
      rxBus.println(makeChk(seq));
      lastSend = now;
      nextToSend++;
    }

    // Recepción continua en RX dedicado
    while (rxBus.available()) {
      String line = rxBus.readStringUntil('\n');
      line.trim();
      if (line.length() == 0) continue;

      // ¿Es ACK?
      uint32_t seqAck = 0; bool isAck = false;
      if (parseAck(line, seqAck, isAck)) {
        if (isAck && seqAck >= SEQ_OFFSET && seqAck < (SEQ_OFFSET + NUM_PACKETS)) {
          myAcked++;
        }
        continue;
      }

      // ¿Es trama RX?
      uint32_t seq = 0;
      bool ok = parseFrame(line, seq);
      if (ok) {
        rx_valid++;
        // Responder ACK al emisor
        rxBus.print("A:");
        rxBus.println(seq);
      } else {
        rx_errors++;
        // Responder NAK (opcional)
        rxBus.print("N:");
        rxBus.println(seq);
      }
    }

    // Condición de fin: ya envié N y recibí N ACKs (o pasó un colchón de tiempo tras el último envío)
    if (nextToSend >= NUM_PACKETS && myAcked >= NUM_PACKETS) break;
  }

  t_end_ms = millis();

  tx_successes = myAcked;
  float total_s = (t_end_ms - t_start_ms) / 1000.0f;
  float succ_rate = 100.0f * (float)tx_successes / (float)NUM_PACKETS;
  float thr = (float)NUM_PACKETS / total_s;

  Serial.println(F("----- RESULTADOS Full-Duplex -----"));
  Serial.print(F("Paquetes TX: ")); Serial.println(NUM_PACKETS);
  Serial.print(F("Tiempo: "));      Serial.print(total_s, 2); Serial.println(F(" s"));
  Serial.print(F("TX éxito: "));    Serial.print(succ_rate, 1); Serial.println(F(" %"));
  Serial.print(F("RX válidos: "));  Serial.println(rx_valid);
  Serial.print(F("Throughput: "));  Serial.print(thr, 1); Serial.println(F(" pkt/s"));
  Serial.println(F("----------------------------------"));
}
#endif

// ========================= SETUP / LOOP =========================
void setup() {
  Serial.begin(115200);
  delay(100);
  beginBuses();
  delay(100);

#if MODE_SIMPLEX_MASTER
  Serial.println(F(">> MODO: SIMPLEX MASTER"));
#endif
#if MODE_SIMPLEX_SLAVE
  Serial.println(F(">> MODO: SIMPLEX SLAVE"));
#endif
#if MODE_FULL_DUPLEX_PEER
  Serial.println(F(">> MODO: FULL-DUPLEX PEER"));
#endif
}

void loop() {
#if MODE_SIMPLEX_MASTER
  runSimplexMaster();
  while (1) { /* fin */ }
#endif

#if MODE_SIMPLEX_SLAVE
  runSimplexSlave();
  while (1) { /* fin */ }
#endif

#if MODE_FULL_DUPLEX_PEER
  runFullDuplexPeer();
  while (1) { /* fin */ }
#endif
}
