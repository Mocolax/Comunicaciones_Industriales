// UNO_B_full_duplex.ino
// Esclavo full duplex con dos módulos max485 y dos buses.
// Recibe valor del potenciómetro, mueve servo y envía acuse.
// Pines
//   RX bus uno: SoftwareSerial RX D10 TX D9 no usado  DE D4 bajo   RE D5 bajo
//   TX bus dos: SoftwareSerial TX D8  RX D7 no usado  DE D2 alto   RE D3 alto
//   Servo: D6
#include <SoftwareSerial.h>
#include <Servo.h>

// RX bus uno
const uint8_t RX_RX = 10;
const uint8_t RX_TX_DUMMY = 9;
const uint8_t RX_DE = 4;
const uint8_t RX_RE = 5;
// TX bus dos
const uint8_t TX_TX = 8;
const uint8_t TX_RX_DUMMY = 7;
const uint8_t TX_DE = 2;
const uint8_t TX_RE = 3;
// Servo
const uint8_t PIN_SERVO = 6;

SoftwareSerial S_RX(RX_RX, RX_TX_DUMMY);  // RX, TX
SoftwareSerial S_TX(TX_RX_DUMMY, TX_TX);  // RX, TX
Servo servo;

uint8_t cs(const uint8_t* d, uint8_t n) {
  uint16_t s = 0;
  for (uint8_t i = 0; i < n; i++) s += d[i];
  return s & 0xFF;
}

void setup() {
  pinMode(RX_DE, OUTPUT); pinMode(RX_RE, OUTPUT);
  digitalWrite(RX_DE, LOW); digitalWrite(RX_RE, LOW);
  pinMode(TX_DE, OUTPUT); pinMode(TX_RE, OUTPUT);
  digitalWrite(TX_DE, HIGH); digitalWrite(TX_RE, HIGH);

  S_RX.begin(9600);
  S_TX.begin(9600);
  Serial.begin(9600);
  servo.attach(PIN_SERVO);
  servo.write(90);
  Serial.println("Esclavo full duplex listo");
}

void enviarAck(uint16_t dato, uint8_t tipo, uint8_t seq) {
  uint8_t hi = (dato >> 8) & 0xFF;
  uint8_t lo = dato & 0xFF;
  uint8_t pkt[5] = {tipo, hi, lo, seq, 0x00};
  pkt[4] = cs(pkt, 4);
  S_TX.write(pkt, 5);
}

void loop() {
  static uint8_t buf[5];
  static uint8_t idx = 0;

  while (S_RX.available()) {
    buf[idx++] = S_RX.read();
    if (idx == 5) {
      idx = 0;
      if (buf[4] == cs(buf, 4)) {
        uint16_t value = (uint16_t(buf[1]) << 8) | buf[2];
        int ang = map(value, 0, 1023, 0, 180);
        servo.write(ang);
        Serial.print("RX val "); Serial.print(value);
        Serial.print(" ang "); Serial.println(ang);
        enviarAck(ang, 0x81, buf[3]);
      } else {
        Serial.println("CRC error");
      }
    }
  }
}
