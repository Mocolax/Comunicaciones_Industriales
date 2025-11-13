# Punto 2 — Comunicación RS-485 entre Raspberry Pi y Arduino (Modbus RTU)

Este punto del laboratorio se enfocó en implementar una **comunicación industrial RS-485** entre una **Raspberry Pi** y un **Arduino**, aplicando la estructura maestro-esclavo del protocolo **Modbus RTU**.  
El objetivo principal fue evidenciar el intercambio confiable de datos entre ambos dispositivos a través de un medio diferencial, propio de los entornos industriales donde se requiere robustez frente a interferencias electromagnéticas y largas distancias de transmisión.

---

## Descripción general del montaje

El sistema estuvo conformado por una **Raspberry Pi (maestro)** y un **Arduino Uno (esclavo)**, conectados mediante módulos **MAX485** que permiten la conversión de niveles TTL a RS-485.  
Cada módulo posee pines de control **DE** y **RE**, los cuales determinan si el dispositivo transmite o recibe datos.

---

## Conexión del bus RS-485

La conexión se realizó de manera diferencial, uniendo los terminales **A+** y **B−** de ambos módulos.  
Adicionalmente, se enlazaron las masas (GND) para mantener referencia común.  
En el caso de la Raspberry Pi, los pines **GPIO17** y **GPIO18** se emplearon para controlar las líneas **DE** y **RE**, respectivamente.

| Dispositivo | Pin función | Conexión | Descripción |
|--------------|--------------|-----------|--------------|
| Raspberry Pi | GPIO17 (DE) | Módulo MAX485 | Control transmisión |
| Raspberry Pi | GPIO18 (RE) | Módulo MAX485 | Control recepción |
| Raspberry Pi | TX/RX UART  | Módulo MAX485 | Datos serie |
| Arduino Uno  | 10 (RX) / 11 (TX) | Módulo MAX485 | Canal de comunicación |
| Ambos        | A+ ↔ A+, B− ↔ B− | Bus RS-485 | Enlace diferencial |
| Ambos        | GND ↔ GND | Tierra común | Referencia eléctrica |

---

## Programación y funcionamiento

### Raspberry Pi
El script desarrollado en Python controla la transmisión y recepción de datos a través del puerto serial `/dev/serial0`.  
Los pines **GPIO17** y **GPIO18** alternan entre los modos de transmisión (TX) y recepción (RX), enviando periódicamente un mensaje al Arduino y escuchando su respuesta.

El flujo de trabajo es el siguiente:
1. Se habilita el modo de transmisión (DE y RE en alto).
2. Se envía el mensaje *“Hola desde Raspberry Pi”*.
3. Se cambia al modo recepción (DE y RE en bajo).
4. Se espera la respuesta proveniente del esclavo.
5. 
<img src="./Conexion Rasberry.jpg" width="45%">
<img src="./onsola Rasberry.jpg" width="45%">

---

### Arduino 
El Arduino escucha constantemente el bus RS-485.  
Cuando recibe un mensaje desde la Raspberry Pi, responde con *“Hola desde Arduino”*.  
Para ello, se utilizaron los pines 10 (RX) y 11 (TX) mediante la librería `SoftwareSerial`, y los pines 2 y 3 para controlar **DE** y **RE** del módulo MAX485.

<img src="./Conexion Arduino.jpg" width="45%">
<img src="./onsola Arduino.jpg" width="45%">

---

## Resultados experimentales

Durante la ejecución, se observó un intercambio continuo de mensajes entre ambos dispositivos, evidenciando el funcionamiento bidireccional del enlace RS-485.  
En la consola de la Raspberry Pi se imprimían las líneas:



