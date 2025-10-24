// -------------------------
//  Comunicación Half-Duplex - Esclavo
// -------------------------

const int EnTxPin = 2;   // Control de dirección RS485: HIGH=TX, LOW=RX
int valor_recibido = 0;  // Dato recibido desde el maestro

void setup() 
{
  Serial.begin(9600);
  Serial.setTimeout(100); 
  pinMode(EnTxPin, OUTPUT);
  digitalWrite(EnTxPin, LOW); // Modo recepción inicial
}

void loop() 
{
  // --- Esperar inicio de trama ---
  if (Serial.find("I")) 
  {
    char comando = Serial.read();
    
    // Comando "S" = recibe un valor del maestro (ángulo)
    if (comando == 'S') 
    {
      valor_recibido = Serial.parseInt();
      if (Serial.read() == 'F') 
      {
        // Guardamos el valor recibido (simulación de lectura)
      }
    }

    // Comando "L" = solicitud de lectura del maestro
    else if (comando == 'L') 
    {
      if (Serial.read() == 'F') 
      {
        // Simula el "sensor" modificando el dato recibido
        int dato_modificado = valor_recibido + 45;
        
        // --- Enviar respuesta al maestro ---
        digitalWrite(EnTxPin, HIGH);  // Cambiar a modo transmisión
        Serial.print("i");
        Serial.print(dato_modificado);
        Serial.print("f");
        Serial.flush();
        digitalWrite(EnTxPin, LOW);   // Volver a modo recepción
      }
    }
  }
}
