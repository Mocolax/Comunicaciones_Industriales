## Codigo ASCII

El código ASCII (American Standard Code for Information Interchange) es un sistema de codificación creado en 1963 por el comité ASA X3.4 en Estados Unidos, con el objetivo de estandarizar la representación de caracteres en dispositivos electrónicos. Consiste en una tabla que asigna un número entero (de 0 a 127 en su versión original) a cada carácter, incluyendo letras, números, signos de puntuación y comandos de control como salto de línea o retroceso.

Su relevancia histórica radica en que fue el primer estándar ampliamente adoptado para el intercambio de información entre computadoras, impresoras, terminales y redes. Al establecer un lenguaje común de 7 bits, permitió la compatibilidad entre diferentes fabricantes y sistemas operativos en una época en la que cada compañía utilizaba su propio formato. Además, sentó las bases para estándares posteriores, como el ASCII extendido de 8 bits y el sistema Unicode, que amplió la codificación a miles de caracteres de múltiples idiomas.

## Protocolo RS232

El RS-232 (Recommended Standard 232) es un protocolo de comunicación en serie definido originalmente por la EIA (Electronics Industries Alliance) en los años 60 para estandarizar el intercambio de datos entre computadoras y periféricos.
Se caracteriza por ser asíncrono y transmitir la información bit a bit a través de una sola línea de datos por dirección (TX y RX), junto con señales de control.
Fue ampliamente usado para conectar:
- Computadoras con módems.
- Equipos industriales (PLC, CNC, instrumentos de medición).
- Consolas de configuración de routers, switches y otros dispositivos.
- Comunicación entre microcontroladores y PCs (aunque hoy se usa más USB-Serial).

Características principales:
- Modo de transmisión: Serie, asíncrona.
- Distancia máxima: ~15 metros (a 19.200 bps) — aunque con cableado de buena calidad y menor velocidad se puede llegar más lejos.
- Velocidades típicas: Desde 300 bps hasta 115.200 bps (o más en implementaciones modernas).
- Niveles de voltaje:
    - Lógico “1” (MARK): entre −3 V y −15 V.
    - Lógico “0” (SPACE): entre +3 V y +15 V.
    - Zona entre −3 V y +3 V es “indefinida”.

- Topología: Punto a punto (un transmisor y un receptor).
- Conectores comunes: DB-9 y DB-25 (aunque la norma no exige un conector específico).