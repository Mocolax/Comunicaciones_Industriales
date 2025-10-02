#include <SoftwareSerial.h>
SoftwareSerial link(2, 3); // RX=2, TX=3

String currentMsg = "";   // último mensaje activo
bool hasMsg = false;      // indica si hay un mensaje circulando

void setup() {
  Serial.begin(115200);
  link.begin(38400);
  Serial.println(F("Nodo listo. Escribe mensaje y ENTER."));
}

void loop() {
  // --- Entrada desde PC ---
  if (Serial.available()) {
    String msg = Serial.readStringUntil('\n');
    if (msg.endsWith("\r")) msg.remove(msg.length() - 1);
    if (msg.length() > 0) {
      currentMsg = msg;
      hasMsg = true;
      Serial.print(F("[TX nuevo] ")); Serial.println(currentMsg);
      link.println(currentMsg);  // lo lanza a la red
    }
  }

  // --- Entrada desde el enlace ---
  if (link.available()) {
    String msg = link.readStringUntil('\n');
    if (msg.endsWith("\r")) msg.remove(msg.length() - 1);
    if (msg.length() > 0) {
      currentMsg = msg;   // actualiza con lo recibido
      hasMsg = true;
      Serial.print(F("[RX] ")); Serial.println(currentMsg);
    }
  }

  // --- Reenvío infinito ---
  if (hasMsg) {
    link.println(currentMsg);
    delay(200); // controla la velocidad del eco (ajusta si hace falta)
  }
}
