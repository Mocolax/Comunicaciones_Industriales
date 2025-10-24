// -------------------------------------
//  Comunicación Full-Duplex - Maestro
// -------------------------------------

const int ledPin = 13;  // Pin del LED indicador

void setup() 
{ 
  Serial.begin(9600);
  Serial.setTimeout(100);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
} 
 
void loop() 
{ 
  // --- Lectura de respuesta del esclavo ---
  if (Serial.available()) 
  {
    if (Serial.read() == 'i')  // inicio de trama
    {
      int dato = Serial.parseInt(); // dato numérico recibido
      if (Serial.read() == 'f')     // fin de trama
      {
        // Resta 50 al valor recibido
        dato = dato - 50;  
        funcion(dato);
      }
    }
  }
  
  // --- Lectura del potenciómetro ---
  int lectura = analogRead(A0);  // valor entre 0 y 1023
  int angulo = map(lectura, 0, 1023, 0, 180);  // convertir a ángulo
  
  // --- Enviar el ángulo al esclavo ---
  Serial.print("I");
  Serial.print("S");
  Serial.print(angulo);
  Serial.print("F");
  
  delay(50);
  
  // --- Solicitar lectura del esclavo ---
  Serial.print("I");
  Serial.print("L");
  Serial.print("F");
  
  delay(50);
}

// --- Función que controla el LED según el valor recibido ---
void funcion(int dato) 
{
  if (dato > 500)
    digitalWrite(ledPin, HIGH);
  else
    digitalWrite(ledPin, LOW);
}
