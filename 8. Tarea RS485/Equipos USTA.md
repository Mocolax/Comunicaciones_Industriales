# Clasificación de Dispositivos por Protocolos de Comunicación Industrial

La siguiente tabla muestra la compatibilidad de diferentes dispositivos con los protocolos **Modbus**, **AS-Interface (AS-i)**, **Ethernet**, **Profibus**, **Profinet** y **RS485**, junto con una breve descripción técnica de cada uno.

| Dispositivo | Modbus | AS-i | Ethernet | Profibus | Profinet | RS485 |
|--------------|--------|------|-----------|-----------|-----------|--------|
| **MiniKelso** | ❌ | ❌ | ❌ | ❌ | ❌ | ❌ |
| **Pepper Robot** | ✅ *(Modbus TCP opcional)* | ❌ | ✅ | ❌ | ✅ | ❌ |
| **Drone AWS DeepRacer** | ❌ | ❌ | ✅ | ❌ | ❌ | ❌ |
| **TurtleBot3** | ❌ | ❌ | ✅ | ❌ | ❌ | ❌ |
| **Darwin Robot** | ❌ | ❌ | ✅ | ❌ | ❌ | ❌ |
| **Minicomputadora Gamer** | ❌ | ❌ | ✅ | ❌ | ❌ | ❌ |
| **Poppy SmallSize** | ❌ | ❌ | ✅ | ❌ | ❌ | ❌ |
| **Impresoras 3D** | ✅ *(Modbus RTU en controladores avanzados)* | ❌ | ✅ | ❌ | ❌ | ✅ |
| **Cámaras Industriales** | ❌ | ❌ | ✅ *(GigE Vision)* | ❌ | ❌ | ❌ |
| **Generador de Señales** | ✅ *(Modbus o SCPI sobre RS485)* | ❌ | ✅ | ❌ | ❌ | ✅ |
| **Fuente Sencilla** | ❌ | ❌ | ❌ | ❌ | ❌ | ❌ |
| **Fuente Dual** | ❌ | ❌ | ❌ | ❌ | ❌ | ❌ |
| **Osciloscopio** | ❌ | ❌ | ✅ *(LAN/SCPI)* | ❌ | ❌ | ❌ |
| **Raspberry Pi 3 / 4** | ✅ *(por software – Modbus TCP/RTU)* | ❌ | ✅ | ❌ | ❌ | ✅ |
| **Jetson Nano** | ✅ *(Modbus TCP vía Python)* | ❌ | ✅ | ❌ | ❌ | ✅ |
| **FPGA DE10 Nano** | ❌ | ❌ | ✅ | ❌ | ❌ | ❌ |
| **Robot Educacional (Lego / Parrot / F1)** | ❌ | ❌ | ✅ *(Wi-Fi o USB)* | ❌ | ❌ | ❌ |
| **Router / Modem / Cajas de Modem** | ❌ | ❌ | ✅ | ❌ | ❌ | ❌ |
| **Controlador de Carga Solar** | ✅ *(Modbus RTU)* | ❌ | ❌ | ❌ | ❌ | ✅ |
| **Panel Solar / Sistema Solar** | ✅ *(en inversores solares con Modbus)* | ❌ | ✅ *(Ethernet solar monitoring)* | ❌ | ❌ | ✅ |
| **Fuente Programable DC** | ✅ *(Modbus RTU o TCP)* | ❌ | ✅ | ❌ | ❌ | ✅ |
| **Osciloscopio (avanzado)** | ✅ *(Modbus TCP opcional)* | ❌ | ✅ | ❌ | ❌ | ✅ |
| **Módulo de Adquisición de Datos (DAQ)** | ✅ *(Modbus RTU/TCP)* | ❌ | ✅ | ❌ | ✅ *(en algunos modelos)* | ✅ |
| **Microcontrolador C2000 / DSP** | ✅ *(via UART-RS485)* | ❌ | ✅ *(Ethernet en variantes avanzadas)* | ❌ | ❌ | ✅ |
| **Nport (Servidor Serial a Ethernet)** | ✅ *(Conversión Modbus RTU/TCP)* | ❌ | ✅ | ❌ | ❌ | ✅ |
| **Caudalímetro Industrial** | ✅ *(Modbus RTU)* | ❌ | ❌ | ✅ *(en modelos Siemens)* | ✅ *(en modelos nuevos)* | ✅ |
| **Estación Meteorológica / MPPT / Controlador Solar** | ✅ *(Modbus RTU o TCP)* | ❌ | ✅ | ❌ | ❌ | ✅ |
| **Banco de Relés / PLC / Reostato / Motor Tool** | ✅ *(Modbus RTU o TCP)* | ❌ | ✅ *(si está conectado a red)* | ✅ *(en PLCs Siemens)* | ✅ *(en PLCs Siemens)* | ✅ |

---

## Descripción de los Equipos y Características

### Pepper Robot
- **Qué es:** Robot humanoide colaborativo desarrollado por SoftBank Robotics.  
- **Para qué sirve:** Interacción con humanos, asistencia, educación e investigación.  
- **Características:** Conectividad Ethernet, sensores de visión, micrófonos y cámaras.  
- **Ventajas:** Capacidad de aprendizaje e integración con redes industriales (Profinet, Modbus TCP).  
- **Desventajas:** Alto costo y mantenimiento especializado.  

---

### AWS DeepRacer
- **Qué es:** Vehículo autónomo a escala diseñado por Amazon.  
- **Para qué sirve:** Entrenamiento y pruebas de modelos de inteligencia artificial.  
- **Características:** Comunicación Wi-Fi y Ethernet, sensores de visión y LIDAR.  
- **Ventajas:** Ideal para aprendizaje de machine learning.  
- **Desventajas:** Limitado a entornos de simulación o educativos.  

---

### TurtleBot3
- **Qué es:** Robot móvil programable basado en ROS (Robot Operating System).  
- **Para qué sirve:** Investigación en robótica, navegación y SLAM.  
- **Características:** Ethernet/Wi-Fi, sensores LIDAR, control por ROS.  
- **Ventajas:** Modular, económico y compatible con Linux y ROS.  
- **Desventajas:** Baja capacidad de carga y potencia limitada.  

---

### Jetson Nano
- **Qué es:** Minicomputadora de NVIDIA enfocada en IA y robótica.  
- **Para qué sirve:** Procesamiento de visión e inferencia neuronal en tiempo real.  
- **Características:** Ethernet, GPIO, compatibilidad con Modbus TCP mediante software.  
- **Ventajas:** Alta capacidad de cómputo, bajo consumo.  
- **Desventajas:** Requiere buena ventilación y fuente estable.  

---

### Nport (Servidor Serial a Ethernet)
- **Qué es:** Convertidor industrial de puerto serial a Ethernet (RS232/RS485 ↔ TCP/IP).  
- **Para qué sirve:** Integrar dispositivos Modbus RTU en redes Ethernet.  
- **Características:** Soporte Modbus TCP/RTU, configuración web, protocolos TCP/IP.  
- **Ventajas:** Permite modernizar equipos antiguos.  
- **Desventajas:** Requiere configuración de red y direccionamiento IP.  

---

### Controlador de Carga Solar
- **Qué es:** Dispositivo que regula la carga y descarga de baterías solares.  
- **Para qué sirve:** Proteger baterías y optimizar la energía solar.  
- **Características:** Modbus RTU, RS485, pantallas LCD.  
- **Ventajas:** Eficiencia energética y comunicación con sistemas SCADA.  
- **Desventajas:** Limitado a sistemas solares DC.  

---

### Panel Solar / MPPT / Inversor Solar
- **Qué es:** Conjunto de elementos para conversión y control de energía solar.  
- **Para qué sirve:** Generación y monitoreo de energía eléctrica desde paneles fotovoltaicos.  
- **Características:** Comunicación Modbus RTU/TCP, RS485, Ethernet.  
- **Ventajas:** Permite monitoreo remoto y control energético.  
- **Desventajas:** Costo elevado en sistemas grandes.  

---

### Raspberry Pi 3 / 4
- **Qué es:** Minicomputadora educativa y de desarrollo.  
- **Para qué sirve:** Automatización, IoT, robótica y control industrial.  
- **Características:** Soporta Modbus TCP/RTU, RS485, y Ethernet.  
- **Ventajas:** Bajo costo, alta versatilidad.  
- **Desventajas:** No apta para ambientes industriales sin encapsulado.  

---

### Módulo de Adquisición de Datos (DAQ)
- **Qué es:** Equipo que toma señales analógicas o digitales para análisis o control.  
- **Para qué sirve:** Monitorizar sensores y variables físicas.  
- **Características:** Comunicación Modbus RTU/TCP, Ethernet y RS485.  
- **Ventajas:** Alta precisión, integración con PLC y SCADA.  
- **Desventajas:** Precio elevado según resolución.  

---

### Microcontrolador C2000 / DSP
- **Qué es:** Dispositivo de control digital de señal de Texas Instruments.  
- **Para qué sirve:** Control de motores, conversión de energía y sistemas embebidos.  
- **Características:** Comunicación UART, SPI, RS485 y Modbus implementable.  
- **Ventajas:** Alta velocidad y precisión.  
- **Desventajas:** Curva de aprendizaje técnica.  

---

### Generador de Señales
- **Qué es:** Instrumento para generar señales eléctricas de prueba.  
- **Para qué sirve:** Calibrar, probar y caracterizar sistemas electrónicos.  
- **Características:** Modbus/SCPI, RS485 y Ethernet.  
- **Ventajas:** Precisión y control remoto.  
- **Desventajas:** Costoso en versiones programables.  

---

### Cámaras Industriales
- **Qué es:** Dispositivos de visión artificial para procesos de control o inspección.  
- **Para qué sirve:** Capturar imágenes para análisis automatizado.  
- **Características:** GigE Vision, Ethernet, compatibilidad con ROS/IA.  
- **Ventajas:** Alta resolución y velocidad.  
- **Desventajas:** Precio elevado y configuración avanzada.  
