int Led = 10;

void setup() {
  Serial.begin(9600);   // debe coincidir con el baudrate de pyserial
  pinMode(Led, OUTPUT);  // LED integrado en la mayoría de placas
}

void loop() 
{
  if (Serial.available() > 0) 
  {
    char dato = Serial.read();   // leer 1 byte
    Serial.print("Recibí: ");
    Serial.println(dato);

    // ejemplo tonto: encender o apagar LED
    if (dato == 'e') 
    {
      digitalWrite(Led, HIGH);
    } 
    else if (dato == 'a') 
    {
      digitalWrite(Led, LOW);
    }
  }
}