# Comunicación Simplex

La comunicación *simplex* es un modo de transmisión en el cual los datos fluyen **en un solo sentido**.  
En el contexto del estándar RS485 —como lo describe Naylamp Mechatronics— esto significa que un dispositivo actúa únicamente como transmisor y otro únicamente como receptor. :contentReference[oaicite:3]{index=3}

## Características principales
- Sólo hay un canal activo para enviar datos, sin posibilidad de que el receptor responda por el mismo canal.  
- Es ideal cuando la información va siempre de un punto A hacia un punto B, sin necesidad de retroalimentación.  
- En una implementación con Arduino y módulo RS-485, el transmisor envía los datos a través de los pines A y B, y el receptor sólo escucha. :contentReference[oaicite:4]{index=4}

## uso
Implementación de dos placas Arduino conectadas mediante módulos RS-485.  
Una de ellas lee un potenciómetro, convierte la lectura en un ángulo, y lo envía al otro Arduino. El segundo recibe ese valor y mueve un servomotor de acuerdo al ángulo recibido.  
En este escenario, el segundo Arduino **no envía nada de vuelta**: la comunicación va únicamente de transmisor → receptor. :contentReference[oaicite:5]{index=5}

## Ventajas y desventajas
**Ventajas**  
- Simplicidad en el cableado y en el protocolo: sólo se transmite en una dirección.  
- Menor complejidad de gestión, ya que no se tienen que coordinar respuestas o modos de recepción/transmisión.

**Desventajas**  
- No permite respuesta ni control bidireccional: el receptor queda sin voz.  
- Menos flexible en sistemas donde se requiere interacción o confirmación de recepción.
