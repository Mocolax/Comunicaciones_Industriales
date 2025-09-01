# MAX232 y sus variantes
## Descripción general

El MAX232 es un circuito integrado que convierte niveles lógicos TTL/CMOS (0–5 V o 0–3.3 V) a los niveles eléctricos RS-232 (±3 a ±15 V).
Funciona mediante bombas de carga internas con capacitores externos, lo que le permite generar las tensiones necesarias a partir de una única alimentación positiva (+5 V).
Se usa principalmente para conectar microcontroladores con dispositivos que implementan el estándar RS-232, como PCs, módems o equipos industriales.

## Prestaciones típicas:
- Alimentación: +5 V.
- Incluye 2 transmisores (drivers) y 2 receptores.
- Soporta comunicación full duplex.
- Velocidades de hasta 120 kbps.
- Necesita 4 capacitores externos (dependiendo de la versión).

## Variantes destacadas
- MAX232A: igual al MAX232 pero usa capacitores más pequeños (0.1 µF).
- MAX202: no requiere capacitores externos.
- MAX3232: funciona con alimentación de 3 V a 5 V, compatible con micros modernos.
- MAX233: incluye los capacitores integrados en el chip.
- MAX220–MAX249: familia con diferentes combinaciones de transmisores/receptores.

## Aplicaciones
- Interconexión de microcontroladores con PCs vía RS-232.
- Comunicación con módems, routers o equipos de telecomunicaciones antiguos.
- Conexión a instrumentos industriales y de laboratorio que usen RS-232.
- Consolas de configuración de dispositivos de red.

| Variante   | Alimentación | Capacitores externos | Canales (Tx/Rx) | Características principales            |
|------------|--------------|----------------------|-----------------|----------------------------------------|
| MAX232     | 5 V          | Sí (4x 1–10 µF)      | 2 / 2           | Versión clásica, estándar               |
| MAX232A    | 5 V          | Sí (4x 0.1 µF)       | 2 / 2           | Igual al MAX232 pero con capacitores más pequeños |
| MAX202     | 5 V          | No                   | 2 / 2           | No requiere capacitores externos        |
| MAX3232    | 3–5 V        | Sí (0.1 µF típicos)  | 2 / 2           | Compatible con micros de 3.3 V          |
| MAX233     | 5 V          | No (integrados)      | 2 / 2           | Capacitores integrados en el chip       |
| MAX220–249 | 3–5 V        | Depende del modelo   | Variados        | Distintas configuraciones Tx/Rx         |
