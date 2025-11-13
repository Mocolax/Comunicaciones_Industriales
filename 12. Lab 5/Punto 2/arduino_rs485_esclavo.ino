#include <SoftwareSerial.h>

#define DE 2
#define RE 3
#define RX 10
#define TX 11

SoftwareSerial RS485(RX, TX); // RX, TX

void setup() {
  Serial.begin(9600);    // Consola USB
  RS485.begin(9600);     // Comunicación RS485
  
  pinMode(DE, OUTPUT);
  pinMode(RE, OUTPUT);

  digitalWrite(DE, LOW);
  digitalWrite(RE, LOW);

  Serial.println("Arduino listo (RS485 en pines 10 y 11)");
}

void loop() {
  if (RS485.available()) {
    String msg = RS485.readStringUntil('\n');
    Serial.println("Recibido desde Raspberry: " + msg);

    // Respuesta
    digitalWrite(DE, HIGH);
    digitalWrite(RE, HIGH);
    RS485.println("Hola desde Arduino");
    delay(10);
    digitalWrite(DE, LOW);
    digitalWrite(RE, LOW);
  }
}
