// UNO_B_RX_simplex.ino
// Receptor rs485 simplex. Recibe tramas y controla un servo con PWM.
// Pines
//   RS485 RX: SoftwareSerial RX D10  TX D9 no usado
//   MAX485 control: DE D4 bajo  RE D5 bajo
//   Servo: D6
#include <SoftwareSerial.h>
#include <Servo.h>

const uint8_t PIN_RX = 10;
const uint8_t PIN_TX_DUMMY = 9;
const uint8_t PIN_DE = 4;
const uint8_t PIN_RE = 5;
const uint8_t PIN_SERVO = 6;

SoftwareSerial RS485(PIN_RX, PIN_TX_DUMMY); // RX, TX
Servo servo;

uint8_t checksum(const uint8_t* data, uint8_t n) {
  uint16_t s = 0;
  for (uint8_t i = 0; i < n; i++) s += data[i];
  return s & 0xFF;
}

void setup() {
  pinMode(PIN_DE, OUTPUT);
  pinMode(PIN_RE, OUTPUT);
  digitalWrite(PIN_DE, LOW);
  digitalWrite(PIN_RE, LOW);

  RS485.begin(9600);
  Serial.begin(9600);
  servo.attach(PIN_SERVO);
  servo.write(90);
  Serial.println("Receptor simplex listo");
}

void loop() {
  static uint8_t buf[5];
  static uint8_t idx = 0;

  while (RS485.available()) {
    buf[idx++] = RS485.read();
    if (idx == 5) {
      idx = 0;
      if (buf[4] == checksum(buf, 4)) {
        uint16_t value = (uint16_t(buf[1]) << 8) | buf[2];
        int ang = map(value, 0, 1023, 0, 180);
        servo.write(ang);
        Serial.print("RX ok val "); Serial.print(value);
        Serial.print(" ang "); Serial.println(ang);
      } else {
        Serial.println("CRC error");
      }
    }
  }
}
