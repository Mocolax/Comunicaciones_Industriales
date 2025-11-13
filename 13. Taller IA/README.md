# Taller: Inteligencia Artificial
---

## 1. IA heurística aplicada al manejo de red

### 1.1. Algoritmos heurísticos orientados a detección de errores y gestión de red

En redes industriales se requiere garantizar **disponibilidad**, **seguridad** y **rendimiento** aun con alta carga y fallos. Los algoritmos de IA heurística se utilizan cuando los métodos exactos son demasiado costosos y se buscan soluciones aproximadas pero eficientes.

A continuación se resumen algunos algoritmos clave y su arquitectura funcional típica.

#### Algoritmos Genéticos (GA)

- **Idea:** Inspirados en la evolución natural.  
- **Representación:** Cada individuo (cromosoma) = configuración de red (rutas, reglas de firewall, parámetros de QoS).  
- **Proceso:**  
  1. Población inicial de configuraciones.  
  2. Evaluación con una función de aptitud (latencia, pérdida, seguridad, etc.).  
  3. Operadores de selección, cruce y mutación.  
- **Parámetros típicos:**  
  - Tamaño de población: 20–100 individuos.  
  - Tasa de cruce: 0.7–0.9.  
- **Uso típico:**  
  - Ajuste de reglas de firewall.  
  - Sintonía de parámetros de tráfico y prioridades de colas.

#### Optimización por Colonia de Hormigas (ACO)

- **Idea:** Modela el comportamiento colectivo de hormigas al buscar rutas óptimas.  
- **Arquitectura:**  
  - Grafo de la red = nodos y enlaces.  
  - Cada hormiga recorre el grafo y deja **feromona** en rutas de buena calidad.  
- **Parámetros clave:**  
  - \(\alpha\): peso de la feromona histórica.  
  - \(\beta\): peso de la heurística local (por ejemplo, 1/latencia).  
  - \(\rho\): tasa de evaporación de feromona.  
- **Uso típico:**  
  - Enrutamiento dinámico en redes industriales con cambios de carga y fallos.

#### Optimización por Enjambre de Partículas (PSO)

- **Idea:** Cada partícula es una posible configuración de la red.  
- **Arquitectura:**  
  - Cada partícula mantiene su mejor posición (pbest).  
  - El enjambre comparte la mejor solución global (gbest).  
- **Actualización:** La velocidad y posición se ajustan en función de pbest y gbest.  
- **Uso típico:**  
  - Balanceo de carga en routers.  
  - Sintonía de parámetros de protocolos industriales o control de congestión.

#### Recocido Simulado (SA)

- **Idea:** Imitar el enfriamiento de un material.  
- **Mecánica:**  
  - Se parte de una configuración inicial.  
  - Se generan configuraciones vecinas; algunas peores se aceptan al inicio con cierta probabilidad.  
  - La “temperatura” va disminuyendo y la búsqueda se vuelve más estricta.  
- **Uso típico:**  
  - Optimización de configuraciones complejas: VLANs, tablas de enrutamiento, políticas de seguridad.

#### Redes Neuronales Artificiales (ANN)

- **Idea:** Aprender patrones en el tráfico de red y en registros de eventos.  
- **Arquitectura típica:**  
  - Capa de entrada: métricas de red (latencia, pérdida, número de conexiones, puertos, flags, etc.).  
  - Capas ocultas: extracción de características no lineales.  
  - Capa de salida: clasificación (normal/anómalo) o regresión (predicción de carga, retardo, etc.).  
- **Uso típico:**  
  - Detección de anomalías de red.  
  - Predicción de fallos y mantenimiento predictivo.

#### Árboles de Decisión y Random Forest

- **Idea:** Clasificar eventos de red a partir de umbrales en variables de tráfico.  
- **Arquitectura:**  
  - Árboles de decisión que dividen el espacio de características.  
  - Random Forest = conjunto de árboles que votan (mayoría).  
- **Uso típico:**  
  - Diagnóstico de incidentes (tipo de fallo, severidad, origen probable).  
  - Clasificación de tráfico malicioso vs. normal.

#### Sistemas Expertos Basados en Reglas

- **Idea:** Capturar conocimiento de expertos en reglas IF–THEN.  
- **Componentes:**  
  - Base de conocimiento con reglas.  
  - Motor de inferencia que aplica las reglas a los hechos observados.  
- **Ejemplos de reglas:**  
  - IF tasa de intentos de conexión > umbral AND puerto = 22 THEN bloquear IP origen.  
  - IF latencia media > umbral THEN redirigir tráfico a ruta alternativa.  
- **Uso típico:**  
  - Automatizar decisiones en firewalls y sistemas de detección de intrusos.

#### Aprendizaje por Refuerzo (RL)

- **Idea:** Un agente aprende interactuando con la red.  
- **Arquitectura:**  
  - Estado: métricas de red (carga, colas, alarmas, etc.).  
  - Acción: cambiar rutas, ajustar prioridades, bloquear tráfico, etc.  
  - Recompensa: función que mide rendimiento y seguridad.  
- **Uso típico:**  
  - Routers adaptativos.  
  - Firewalls que actualizan sus reglas en función del comportamiento del tráfico.

---

### 1.2. Industria IoT (IIoT), Ethernet y manejo de datos

La **Industria IoT (IIoT)** integra sensores, actuadores, PLCs y otros dispositivos “inteligentes” conectados a la red. **Ethernet industrial** actúa como columna vertebral para transportar los datos de forma determinista.

#### Relación tecnológica

- La IIoT se encarga de **capturar datos del proceso** industrial.  
- **Ethernet industrial** (Profinet, EtherCAT, Modbus TCP, Ethernet/IP, etc.) proporciona:
  - Alta velocidad de transmisión.  
  - Determinismo y sincronización precisa.  
  - Capacidad de integración con redes IT (TCP/IP).  
- Esto habilita interoperabilidad entre:
  - Campo (sensores/actuadores).  
  - Control (PLCs, PACs).  
  - Supervisión (SCADA/MES).  
  - Nube (análisis avanzado, dashboards, IA).

#### Ventajas

- Comunicación unificada sobre TCP/IP.  
- Baja latencia y alta confiabilidad en redes deterministas (< 1 ms).  
- Monitoreo remoto mediante plataformas IoT (Azure IoT, AWS IoT, etc.).  
- Escalabilidad y facilidad para agregar nuevos nodos.  
- Seguridad reforzada con VLANs, firewalls industriales y cifrado.

#### Ejemplo simple

1. Sensores IoT miden variables de proceso.  
2. Los datos viajan por Ethernet industrial hacia un PLC.  
3. El PLC controla localmente y envía datos a un SCADA y/o a la nube.  
4. Algoritmos de IA (anomaly detection, mantenimiento predictivo) procesan la información y generan alarmas o recomendaciones.

---

### 1.3. Computación cuántica en comunicaciones industriales

La **computación cuántica** explota qubits, superposición y entrelazamiento para resolver ciertos problemas más rápido que la computación clásica.

Aunque aún está en fases tempranas, se visualizan varios usos en comunicaciones industriales:

#### Aplicaciones relevantes

- **Criptografía cuántica (QKD):**  
  - Distribución cuántica de claves con detección automática de intentos de interceptación.  
  - Protección de enlaces entre PLCs, firewalls, centros de control y servicios en la nube.

- **Optimización de red:**  
  - Algoritmos cuánticos para explorar, en paralelo, muchas configuraciones de red.  
  - Potencial para optimizar ruteo, asignación de ancho de banda y planificación de recursos.

- **IA cuántica:**  
  - Entrenamiento acelerado de modelos complejos de mantenimiento predictivo y detección de anomalías.  

#### Arquitectura futura de referencia

1. **Capa física:** enlaces ópticos/satelitales que transportan qubits.  
2. **Capa de comunicación:** protocolos cuánticos (QKD, autenticación).  
3. **Capa de aplicación:** sistemas industriales (SCADA, IIoT, gestores de red) que integran módulos cuánticos para seguridad y análisis.

---

## 2. Propuesta tipo Minciencias

### 2.1. Título tentativo

> **Red Industrial Inteligente con IA Heurística y Seguridad Basada en Computación Cuántica**

### 2.2. Descripción general

La propuesta plantea el diseño de un sistema de comunicaciones industriales inteligente que:

- Use **IA heurística** (PSO o RL) para detectar anomalías y optimizar el tráfico.  
- Integre **técnicas de computación cuántica** (QKD simulada) para fortalecer la seguridad de los datos.  
- Se implemente sobre una red basada en **Ethernet industrial** y protocolos como **Modbus TCP** y **MQTT**.

La idea se alinea con una posible convocatoria de **Minciencias** en el eje:

> *“Innovación en IA y Computación Cuántica aplicada a la Industria 4.0”*.

### 2.3. Problema identificado

Las redes industriales actuales suelen presentar:

- Saturación de tráfico en redes IoT.  
- Vulnerabilidades derivadas de configuraciones estáticas en routers y firewalls.  
- Baja eficiencia en el diagnóstico de fallos y en la gestión dinámica del ancho de banda.

### 2.4. Objetivo general

> **Integrar algoritmos de inteligencia artificial y técnicas de computación cuántica para detectar anomalías y optimizar la comunicación industrial entre dispositivos IoT que operan sobre protocolos Ethernet industriales.**

### 2.5. Objetivos específicos

1. Implementar un modelo de **IA heurística** (PSO o RL) para detectar errores de red y ajustar automáticamente parámetros de comunicación.  
2. Aplicar **criptografía cuántica (QKD)** para asegurar la transferencia de datos industriales entre nodos críticos.  
3. Desarrollar un **prototipo simulado en Python y Simulink** que integre ambos enfoques.  
4. Publicar los resultados en un **repositorio colaborativo de GitHub** con código y documentación.

### 2.6. Arquitectura propuesta

- **Capa física:**  
  - Red Ethernet industrial con nodos IoT (sensores, actuadores), PLC y servidor de control.

- **Capa lógica:**  
  - **Módulo de IA heurística:**  
    - Detección de errores, predicción de congestión y ajuste dinámico de rutas/prioridades.  
  - **Módulo de seguridad cuántica:**  
    - Simulación de QKD para generación y gestión de claves cuánticas.  
    - Integración con protocolos clásicos (TLS/VPN).

- **Capa de aplicación:**  
  - Panel web o dashboard con:
    - Tráfico por enlace, latencia, pérdida de paquetes.  
    - Alertas de fallos/anomalías.  
    - Estado de claves y eventos de seguridad.

### 2.7. Tecnologías a emplear

- **Lenguaje:** Python.  
- **Librerías:** `scikit-learn`, `TensorFlow`, `qiskit`.  
- **Protocolos:** Ethernet/IP, Modbus TCP, MQTT.  
- **Herramientas:** Node-RED, Wireshark, Simulink.  
- **Control de versiones:** Git + GitHub.

### 2.8. Resultados esperados

- Detección de errores en tiempo casi real mediante IA heurística.  
- Optimización automática del flujo de paquetes.  
- Transmisión de datos cifrada usando claves cuánticas simuladas.  
- Base técnica para futuras redes industriales autónomas y seguras.

### 2.9. Impacto

La propuesta contribuye a:

- Fortalecer la **competitividad del sector industrial colombiano** mediante la adopción de IA y tecnologías cuánticas.  
- Alinear desarrollos académicos con las líneas de **Minciencias** en Industria 4.0.  
- Generar capacidades técnicas (código, documentación, prototipos) reutilizables en la industria.

---

## 3. Líderes tecnológicos y cuadro mágico de Gartner

El **cuadro mágico de Gartner** clasifica a los proveedores en cuatro cuadrantes según dos ejes: *capacidad de ejecución* y *integridad de visión*.

- **Leaders (Líderes):**  
  - Alta capacidad de ejecución y visión completa.  
  - Suelen marcar tendencia y dominar el mercado.

- **Challengers (Retadores):**  
  - Alta ejecución, menor visión.  
  - Fuerte presencia, pero con menos innovación o alcance estratégico.

- **Visionaries (Visionarios):**  
  - Alta visión, menor capacidad de ejecución.  
  - Propuestas innovadoras que aún están escalando.

- **Niche Players (Jugadores de nicho):**  
  - Se enfocan en segmentos específicos o soluciones más acotadas.  

### 3.1. Proveedores analizados en este taller

Tabla de referencia para algunos fabricantes relevantes, conectados con temas de red, seguridad e IIoT:

| Proveedor                      | Mercado / MQ relevante                          | Cuadrante        | Fortalezas principales                                                                                 |
|--------------------------------|-------------------------------------------------|------------------|--------------------------------------------------------------------------------------------------------|
| Juniper Networks               | Enterprise Wired & Wireless LAN Infrastructure  | Leaders          | Alta capacidad de ejecución, visión amplia, enfoque “AI-Native Networking”.                           |
| HPE Aruba Networking           | Enterprise Wired & Wireless LAN Infrastructure  | Leaders          | Solución madura, buena cobertura campus/filial, integración de seguridad y nube.                      |
| Huawei Technologies Co., Ltd.  | Enterprise Wired & Wireless LAN Infrastructure  | Leaders          | Innovación fuerte (Wi-Fi 7, CloudCampus), excelente capacidad de ejecución.                           |
| ABB Ltd.                       | Global Industrial IoT Platforms                 | Leaders          | Integración IT/OT, analítica industrial, plataforma escalable para industria.                         |
| Siemens Digital Industries SW  | Global Industrial IoT Platforms                 | Leaders          | Marca sólida en industria, experiencia OT/IT, visión robusta para IIoT.                               |
| Software AG                    | Global Industrial IoT Platforms                 | Leaders          | Plataforma IoT escalable, amplia integración de datos y soluciones industriales.                      |
| AVEVA Group plc                | Global Industrial IoT Platforms                 | Visionaries      | Fuerte en visión e innovación, aunque de menor escala que algunos líderes históricos.                 |
| TP-Link Technologies Co., Ltd. | Enterprise Wired & Wireless LAN Infrastructure  | Niche Players    | Opción económica y especializada, con menor cobertura global o menos funciones avanzadas.             |

### 3.2. Impacto en el contexto del taller

- Los **líderes en LAN empresarial** (Juniper, HPE Aruba, Huawei) son clave para entender cómo la IA ya se integra en redes campus y *data centers* con conceptos como *AI-Native Networking*.  
- Los **líderes en plataformas IIoT** (ABB, Siemens, Software AG) son referencia para el diseño de arquitecturas que combinan campo, control, supervisión y nube.  
- **Visionarios** como AVEVA muestran el camino de soluciones con fuerte enfoque en analítica y visualización industrial.  
- **Jugadores de nicho** como TP-Link ilustran alternativas costo–efectivas para ciertos escenarios o laboratorios.

---

