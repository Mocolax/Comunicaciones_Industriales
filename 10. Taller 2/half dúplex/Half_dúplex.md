# Comunicación Full-Duplex

La comunicación *full-duplex* es el modo más completo: los datos pueden fluir **en ambas direcciones simultáneamente**. Tanto el equipo A puede enviar al B como el B puede enviar al A al mismo tiempo sin interferencia.

## Características principales
- Requiere dos canales o pares de hilos: uno dedicado para la transmisión de A → B y otro para B → A. En el estándar RS-485 esto se logra utilizando cuatro líneas: un par para transmitir y otro para recibir.  
- La gestión es más sencilla, ya que no es necesario “esperar turno” para transmitir o recibir.  
- Es ideal cuando ambos dispositivos necesitan comunicarse de forma continua y simultánea.

##  uso
En esta práctica se implementó la comunicación full-duplex entre un **Arduino maestro** y un **Arduino esclavo**, cada uno con su respectivo módulo RS-485.  
Debido a que no se contaba con un sensor físico, se modificó el código para simular el intercambio de datos:  
- El maestro envía un valor inicial al esclavo.  
- El esclavo recibe ese valor, le **suma 45 grados** y envía el nuevo valor de regreso al maestro.

De esta manera, ambos dispositivos transmiten y reciben datos de forma simultánea, cumpliendo el principio del modo full-duplex. Este método permitió verificar la correcta transmisión en ambas direcciones y observar que no existe interferencia entre los canales.

## Ventajas y desventajas
**Ventajas**  
- Comunicación bidireccional sin demoras por alternar transmisión y recepción.  
- Mayor rendimiento, ya que ambos extremos pueden operar de manera continua.  

**Desventajas**  
- Requiere un mayor número de cables o pares para la transmisión y recepción.  
- En RS-485, normalmente se usa en conexiones punto a punto más que en buses compartidos.  
- Puede implicar un costo o complejidad mayor en el diseño del sistema.
