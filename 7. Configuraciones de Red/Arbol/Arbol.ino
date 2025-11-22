void setup() {
  Serial.begin(9600);   // velocidad de baudios
}

void loop() {
  // Si hay una tecla escrita en el monitor serie
  if (Serial.available() > 0) {
    char tecla = Serial.read();  // lee un solo carácter
    Serial.write(tecla);         // lo envía como byte crudo por UART
  }

  delay(50);  // pequeña pausa para no saturar
}
