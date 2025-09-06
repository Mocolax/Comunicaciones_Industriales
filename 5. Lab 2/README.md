# 📚 Tipos de Técnicas de Detección de Errores

## 1. Bit de Paridad (Parity Bit)
- **Descripción**: Es el método más simple. Se añade un bit extra a un conjunto de bits de datos para que el número total de '1's sea par (paridad par) o impar (paridad impar).
- **Detección**: Solo detecta errores en un número **impar** de bits por carácter (si dos bits cambian, el error pasa desapercibido).
- **Overhead**: Bajo (1 bit extra por trama de datos).
- **Usos**: Comunicaciones simples, memoria RAM (detección de error básica).

## 2. Checksum (Suma de Verificación)
- **Descripción**: Se calcula una suma o operación XOR sobre todos los bytes de un mensaje. Este valor se envía al final del bloque.
- **Detección**: Detecta errores aleatorios, pero es vulnerable a ciertos patrones de error (ej: si dos bytes cambian de valor de manera compensatoria).
- **Variantes**:
  - **Suma simple**: Suma aritmética de los bytes.
  - **XOR**: Operación XOR bit a bit sobre todos los bytes.
- **Overhead**: Bajo (generalmente 1 byte).
- **Usos**: Protocolos de red (TCP, UDP), transferencia de archivos.

## 3. VRC (Vertical Redundancy Check)
- **Descripción**: Esencialmente es un **bit de paridad aplicado por columna (byte a byte)**. Cada carácter o byte lleva su propio bit de paridad.
- **Detección**: Detecta errores en un bit por byte, pero si dos bits en la misma posición de diferentes bytes cambian, el error puede no detectarse.
- **Overhead**: 1 bit por byte (12.5% de overhead en 8 bits).
- **Usos**: Transmisiones de caracteres simples (ej: transmisiones ASCII antiguas).

## 4. LRC (Longitudinal Redundancy Check)
- **Descripción**: Se calcula un bit de paridad **por posición de bit a lo largo de todos los bytes** del mensaje. Al final del mensaje se envía un byte adicional con estos bits de paridad.
- **Detección**: Complementa al VRC. Detecta errores que el VRC podría pasar por alto, especialmente errores en ráfaga.
- **Overhead**: 1 byte extra por mensaje.
- **Usos**: Protocolos industriales como **Modbus RTU**.

## 5. CRC (Cyclic Redundancy Check)
- **Descripción**: Algoritmo matemático robusto que trata los datos como un polinomio grande y los divide por un polinomio generador. El resto de la división (el CRC) se envía con los datos.
- **Detección**: Muy efectivo para detectar:
  - Errores de bit único.
  - Errores de doble bit.
  - Errores en ráfaga (hasta una longitud igual al grado del polinomio).
  - Casi todos los errores impares.
- **Overhead**: Mayor que los anteriores (16, 32 o más bits), pero muy eficiente.
- **Usos**: Ethernet (CRC-32), discos duros, Wi-Fi, ZIP, PNG, y muchos protocolos de comunicación.

---

## 6. ARQ (Automatic Repeat Request)
- **Descripción**: No es un método de detección *per se*, sino un **mecanismo de control de errores** que utiliza detección (usualmente CRC) para solicitar la retransmisión de datos corruptos.
- **Funcionamiento**: El receptor envía un acuse de recibo (ACK) si los datos son correctos, o una solicitud de repetición (NAK) si se detecta un error.
- **Variantes**:
  - **Stop-and-Wait ARQ**: Espera ACK después de cada trama.
  - **Go-Back-N ARQ**: Envía múltiples tramas; si hay error, retrocede y retransmite desde la fallada.
  - **Selective Repeat ARQ**: Retransmite solo la trama específica con error.
- **Usos**: Protocolos de enlace de datos como HDLC, TCP.

---

## 📊 Comparativa Resumida

| Método           | Detección de Errores                          | Overhead       | Complejidad | Uso típico                     |
|------------------|-----------------------------------------------|----------------|-------------|--------------------------------|
| **Bit de Paridad** | Errores impares por byte                      | 1 bit / byte   | Muy baja    | Comunicaciones simples         |
| **Checksum**       | Errores aleatorios, no todos                  | 1-2 bytes      | Baja        | TCP, UDP, archivos             |
| **VRC**            | Errores de 1 bit por byte                     | 1 bit / byte   | Baja        | Transmisiones de caracteres    |
| **LRC**            | Errores en ráfaga, complementa a VRC          | 1 byte / msg   | Media       | Modbus RTU                     |
| **CRC**            | Casi todo tipo de errores, muy robusto        | 16-32 bits     | Alta        | Ethernet, Wi-Fi, discos duros  |
| **ARQ**            | Retransmisión basada en detección (ej: CRC)   | Variable       | Alta        | TCP, HDLC                      |

---

## ✅ Conclusión
Cada método tiene sus ventajas y desventajas. La elección depende de:
- La confiabilidad requerida.
- El overhead tolerable.
- La complejidad de implementación.
- El entorno (ruidoso o limpio).

En sistemas modernos, el **CRC** junto con mecanismos **ARQ** es la combinación más utilizada para garantizar una comunicación confiable.

---

¿Necesitas que profundice en alguno de estos métodos o que te ayude con un ejemplo de cálculo?