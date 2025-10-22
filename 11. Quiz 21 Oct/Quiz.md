# Quiz – Sistema de Automatización Siemens S7-1200

## 1. Visión General

El sistema está basado en un **PLC Siemens SIMATIC S7-1200**, modelo **CPU 1214C DC/DC/DC**, acompañado de módulos de expansión, fuente de alimentación, un switch industrial y un panel HMI.  
Este conjunto permite realizar tareas de control y supervisión industrial con manejo de señales digitales y analógicas, además de comunicación mediante Ethernet y distintos protocolos de campo.

---

## 2. Unidad Central de Control

**Modelo:** SIMATIC S7-1200 CPU 1214C DC/DC/DC  
**Código:** 6ES7 214-1BG40-0XB0  

**Datos técnicos más relevantes:**
- Tensión de alimentación: 24 VDC  
- Entradas digitales: 14 (24 VDC)  
- Salidas digitales: 10 (24 VDC, tipo transistor)  
- Entradas analógicas: 2 (0–10 V, resolución 10 bits)  
- Salidas analógicas: 2 (0–20 mA o 0–10 V)  
- Memoria de programa: 100 KB  
- Memoria de datos: 50 KB  
- Tiempo de procesamiento: 0.08 µs por instrucción  
- Comunicación integrada: PROFINET (Ethernet industrial)  
- Reloj en tiempo real incorporado  
- Compatible con el entorno **TIA Portal** para programación, pruebas y diagnóstico  

---

## 3. Componentes del Sistema

### 3.1 Fuente de Alimentación PM 1207
**Código:** 6EP1332-1SH43  
**Función:** Suministra la tensión de 24 VDC necesaria para el PLC y los módulos conectados.  
- Entrada: 120/230 VAC  
- Salida: 24 VDC / 2.5 A  

---

### 3.2 Módulo de Comunicación CM 1241 (RS422/RS485)
**Código:** 6ES7241-1CH32-0XB0  
**Función:** Proporciona comunicación serial con otros dispositivos industriales.  
**Protocolos disponibles:**
- Modbus RTU (Maestro o Esclavo)  
- Comunicación libre (Freeport) con tramas personalizadas  

---

### 3.3 Módulo de Entradas Analógicas SM 1231 AI
**Código:** 6ES7231-4HF32-0XB0  
**Función:** Incrementa el número de canales analógicos disponibles.  
**Especificaciones:**
- 4 entradas analógicas (0–10 V / 0–20 mA)  
- Resolución de 13 bits  
- Aislamiento galvánico entre canales  

---

### 3.4 Módulo de Salidas Analógicas SM 1232 AQ
**Código:** 6ES7232-4HA30-0XB0  
**Función:** Entrega señales analógicas hacia actuadores o instrumentos.  
**Especificaciones:**
- 2 salidas analógicas (0–10 V / 0–20 mA)  
- Resolución de 12 bits  

---

### 3.5 Tarjeta de Salida Analógica SB 1232 AQ
**Código:** 6ES7232-4HA30-0XB0  
**Función:** Añade una salida analógica directamente sobre la CPU.  
- 1 canal (0–10 V o 0–20 mA)  

---

### 3.6 Switch Industrial Scalance XB005
**Código:** 6GK5005-0BA00-1AB2  
**Función:** Permite la conexión de dispositivos a la red Ethernet industrial.  
**Características:**
- 5 puertos RJ45 (10/100 Mbps)  
- Tipo: no gestionable (Unmanaged)  
- Uso: interconexión entre PLC, HMI, PC y red de supervisión  

---

### 3.7 Panel HMI KTP700 Basic
**Código:** 6AV2 123-2GB03-0AX0  
**Función:** Interfaz gráfica para el control y visualización del sistema.  
**Características:**
- Pantalla táctil de 7” (800×480 píxeles)  
- Comunicación por PROFINET  
- Alimentación: 24 VDC / 0.44 A máx  
- Admite alarmas, variables, tendencias y control de procesos  

---

## 4. Protocolos y Comunicaciones

| Tipo de conexión | Protocolo | Uso principal |
|------------------|-----------|----------------|
| Ethernet industrial | PROFINET | Comunicación entre PLC, HMI y variadores Siemens |
| Ethernet TCP/IP | Modbus TCP | Intercambio de datos con equipos externos o PC |
| Serial RS-422/RS-485 | Modbus RTU | Comunicación punto a punto o multipunto |
| Serial RS-422/RS-485 | Freeport | Tramas definidas por el usuario |
| HMI | HMI Runtime | Sincronización de datos entre el PLC y el panel HMI |
| Programación | TIA Portal | Carga, depuración y diagnóstico por Ethernet |

---

## 5. Resumen de Hardware

| Componente | Función | Código |
|-------------|----------|---------|
| PM 1207 | Fuente de alimentación 24 VDC | 6EP1332-1SH43 |
| CM 1241 | Comunicación serial RS-422/485 | 6ES7241-1CH32-0XB0 |
| CPU 1214C | Control principal | 6ES7214-1BG40-0XB0 |
| SM 1231 AI | Entradas analógicas | 6ES7231-4HF32-0XB0 |
| SM 1232 AQ | Salidas analógicas | 6ES7232-4HA30-0XB0 |
| SB 1232 AQ | Salida analógica adicional | 6ES7232-4HA30-0XB0 |
| Scalance XB005 | Switch industrial Ethernet | 6GK5005-0BA00-1AB2 |
| KTP700 Basic | Panel HMI táctil | 6AV2 123-2GB03-0AX0 |

---

## 6. Alimentación y Conexión

- Tensión principal: 24 VDC  
- Corriente total aproximada: 2.5 A (dependiendo de la carga conectada)  
- Comunicación interna entre módulos mediante **bus posterior (backplane bus)**  

---

## 7. Consideraciones Finales

El sistema **SIMATIC S7-1200** ofrece una arquitectura modular y compacta, ideal para automatización de pequeña y mediana escala.  
Los módulos de expansión (SM y CM) se montan lateralmente a la CPU, mientras que la tarjeta SB se instala en la parte frontal.  
El **Scalance XB005** facilita la integración a redes PROFINET o TCP/IP, y el **KTP700 Basic** brinda una interfaz intuitiva para el operador.

---

## 8. Fuentes de Consulta

- *Siemens S7-1200 System Manual – Edición 2024*  
- *Documentación de TIA Portal V17*  
- *Siemens Industry Online Support (SIOS)*  
  - [https://support.industry.siemens.com](https://support.industry.siemens.com)

