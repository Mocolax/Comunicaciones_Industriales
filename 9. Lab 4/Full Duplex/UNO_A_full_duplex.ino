// UNO_A_full_duplex.ino
// Maestro full duplex con dos módulos max485 y dos buses.
// Envía valor de potenciómetro y escucha confirmaciones.
// Pines
//   TX bus uno: SoftwareSerial TX D8  RX D7 no usado  DE D2 alto  RE D3 alto
//   RX bus dos: SoftwareSerial RX D10 TX D9 no usado  DE D4 bajo   RE D5 bajo
//   Potenciómetro: A0
#include <SoftwareSerial.h>

// TX bus uno
const uint8_t TX_TX = 8;
const uint8_t TX_RX_DUMMY = 7;
const uint8_t TX_DE = 2;
const uint8_t TX_RE = 3;
// RX bus dos
const uint8_t RX_RX = 10;
const uint8_t RX_TX_DUMMY = 9;
const uint8_t RX_DE = 4;
const uint8_t RX_RE = 5;
// Potenciómetro
const uint8_t PIN_POT = A0;

SoftwareSerial S_TX(TX_RX_DUMMY, TX_TX);  // RX, TX
SoftwareSerial S_RX(RX_RX, RX_TX_DUMMY);  // RX, TX

uint8_t seq = 0;

uint8_t cs(const uint8_t* d, uint8_t n) {
  uint16_t s = 0;
  for (uint8_t i = 0; i < n; i++) s += d[i];
  return s & 0xFF;
}

void setup() {
  pinMode(TX_DE, OUTPUT); pinMode(TX_RE, OUTPUT);
  digitalWrite(TX_DE, HIGH); digitalWrite(TX_RE, HIGH);
  pinMode(RX_DE, OUTPUT); pinMode(RX_RE, OUTPUT);
  digitalWrite(RX_DE, LOW); digitalWrite(RX_RE, LOW);

  S_TX.begin(9600);
  S_RX.begin(9600);
  Serial.begin(9600);
  Serial.println("Maestro full duplex listo");
}

void sendPot() {
  int val = analogRead(PIN_POT);
  uint8_t hi = (val >> 8) & 0xFF;
  uint8_t lo = val & 0xFF;
  uint8_t pkt[5] = {0x01, hi, lo, seq, 0x00};
  pkt[4] = cs(pkt, 4);
  S_TX.write(pkt, 5);
  Serial.print("TX val "); Serial.print(val);
  Serial.print(" seq "); Serial.println(seq);
  seq++;
}

void readAck() {
  static uint8_t buf[5];
  static uint8_t idx = 0;
  while (S_RX.available()) {
    buf[idx++] = S_RX.read();
    if (idx == 5) {
      idx = 0;
      if (buf[4] == cs(buf, 4)) {
        uint16_t data = (uint16_t(buf[1]) << 8) | buf[2];
        Serial.print("ACK tipo "); Serial.print(buf[0], HEX);
        Serial.print(" dato "); Serial.print(data);
        Serial.print(" seq "); Serial.println(buf[3]);
      } else {
        Serial.println("ACK con error");
      }
    }
  }
}

void loop() {
  sendPot();
  readAck();
  delay(100);
}
