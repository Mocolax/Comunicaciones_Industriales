const int analogPin = A0;
int value;

void setup() 
{
  Serial.begin(9600);   // velocidad de baudios
}

void loop() 
{
  value = analogRead(analogPin);     // un byte (ejemplo: 'A' en ASCII)
  value = map(value, 0, 1023, 0, 255);
  Serial.write(value);
  delay(50);          // espera 1 segundo
}