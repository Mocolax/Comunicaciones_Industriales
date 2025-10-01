#include <SoftwareSerial.h>
SoftwareSerial link(2, 3); // RX=2, TX=3

void setup() {
  Serial.begin(115200);
  link.begin(38400);
  Serial.println(F("Nodo listo. Cada mensaje se reenvía UNA sola vez."));
}

void loop() {
  // --- Mensaje desde PC ---
  if (Serial.available()) {
    String msg = Serial.readStringUntil('\n');
    if (msg.endsWith("\r")) msg.remove(msg.length() - 1);
    if (msg.length() > 0) {
      Serial.print(F("[PC] ")); Serial.println(msg);
      link.println(msg);  // lo mando una vez
    }
  }

  // --- Mensaje desde UART ---
  if (link.available()) {
    String msg = link.readStringUntil('\n');
    if (msg.endsWith("\r")) msg.remove(msg.length() - 1);
    if (msg.length() > 0) {
      Serial.print(F("[UART] ")); Serial.println(msg);
      Serial.println(msg); // eco de vuelta al PC
    }
  }
}