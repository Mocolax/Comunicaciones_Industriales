# 🧠 Vigilancia Tecnológica de Protocolos Industriales

---

## 🔹 1. Modbus

### ¿Qué es?
**Modbus** es un protocolo de comunicación industrial desarrollado por Modicon (ahora Schneider Electric) en 1979.  
Es uno de los más antiguos y utilizados para conectar dispositivos electrónicos como PLCs, sensores y actuadores dentro de una red industrial.

### ¿Para qué sirve?
Permite **transmitir datos entre dispositivos electrónicos** de control industrial bajo una arquitectura **maestro–esclavo**, facilitando la comunicación entre sistemas de supervisión (SCADA) y equipos de campo.

### Características o tipos
- Protocolos principales: **Modbus RTU**, **Modbus ASCII** y **Modbus TCP/IP**  
- Comunicación **serie (RS-232/RS-485)** y **Ethernet**  
- Estructura de mensajes sencilla  
- Comunicación determinista y confiable  

### Ventajas
- Estándar abierto y gratuito  
- Fácil de implementar y diagnosticar  
- Amplia compatibilidad entre fabricantes  

### Desventajas
- Velocidad limitada (en versiones serie)  
- Sin seguridad integrada  
- Comunicación unidireccional maestro–esclavo  

---

## 🔹 2. AS-Interface (AS-i)

### ¿Qué es?
**AS-Interface (Actuator Sensor Interface)** es un sistema de comunicación industrial diseñado para conectar **sensores y actuadores** a controladores superiores (como PLCs) de forma simple y económica.

### ¿Para qué sirve?
Reduce el cableado necesario entre dispositivos de campo y controladores, utilizando un **único cable plano de dos hilos** que transmite **energía y datos simultáneamente**.

### Características o tipos
- Topología libre: estrella, anillo, árbol o línea  
- Comunicación **maestro–esclavo**  
- Distancia máxima: **100 m** (ampliable con repetidores)  
- Soporta hasta **62 dispositivos** por red  

### Ventajas
- Instalación rápida y económica  
- Cableado reducido (datos + energía en el mismo cable)  
- Compatible con protocolos como **PROFIBUS**, **PROFINET** o **Modbus**  

### Desventajas
- Limitado a aplicaciones de nivel de campo  
- Ancho de banda reducido  
- No apto para tiempos de respuesta extremadamente rápidos  

---
