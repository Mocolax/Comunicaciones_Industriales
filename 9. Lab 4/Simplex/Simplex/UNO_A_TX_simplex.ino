// UNO_A_TX_simplex.ino
// Emisor rs485 simplex. Lee potenciómetro en A0 y envía tramas de 5 bytes.
// Pines
//   RS485 TX: SoftwareSerial TX D8  RX D7 no usado
//   MAX485 control: DE D2  RE D3  ambos en alto
//   Potenciómetro: A0
#include <SoftwareSerial.h>

const uint8_t PIN_TX = 8;
const uint8_t PIN_RX_DUMMY = 7;
const uint8_t PIN_DE = 2;
const uint8_t PIN_RE = 3;
const uint8_t PIN_POT = A0;

SoftwareSerial RS485(PIN_RX_DUMMY, PIN_TX); // RX, TX

uint8_t seq = 0;

uint8_t checksum(const uint8_t* data, uint8_t n) {
  uint16_t s = 0;
  for (uint8_t i = 0; i < n; i++) s += data[i];
  return s & 0xFF;
}

void setup() {
  pinMode(PIN_DE, OUTPUT);
  pinMode(PIN_RE, OUTPUT);
  digitalWrite(PIN_DE, HIGH);
  digitalWrite(PIN_RE, HIGH);

  RS485.begin(9600);
  Serial.begin(9600);
  Serial.println("Emisor simplex listo");
}

void loop() {
  int val = analogRead(PIN_POT);        // 0..1023
  uint8_t hi = (val >> 8) & 0xFF;
  uint8_t lo = val & 0xFF;
  uint8_t pkt[5] = {0x01, hi, lo, seq, 0x00};
  pkt[4] = checksum(pkt, 4);

  RS485.write(pkt, 5);
  Serial.print("TX val "); Serial.print(val);
  Serial.print(" seq "); Serial.println(seq);

  seq++;
  delay(100);
}
