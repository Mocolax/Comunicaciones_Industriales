# Laboratorio 3

# Mateo Gutierrez, Nicolas Alfonso, Julian Montealegre

## Objetivos del Laboratorio
 1. Configurar y explorar un switch básico (24/48 puertos) de la Universidad Santo
 Tomás.
 2. Desarrollar y probar diferentes conexiones topológicas de red utilizando PCs y Ar
duinos conectados por LAN.
 3. Documentar la práctica y anexarla al repositorio en GitHub.
## Punto 1: Conociendo el switch y la red interna
 En este punto se realizó la configuración inicial del switch mediante el software
 PuTTY y el protocolo de conexión correspondiente.
### Actividades desarrolladas
 Visualización de información en memoria NVRAM.
 Identificación de la MAC address y su significado.
 Habilitación del switch y creación de interfaces VLAN con máscaras /24, /16 y
 /8.
 Configuración de usuarios, puertas de enlace y revisión de la versión del dispositivo.
 Exploración de puertos en modo troncal y acceso.
 Revisión de la tabla ARP y velocidades de cada interfaz.
 Conexión de dispositivos: PCs y Arduinos a través de LAN.
 Verificación de conectividad a Internet y comunicación entre los equipos.
 ## Punto 2: Desarrollo de conexiones topológicas
Se implementaron diferentes **topologías de red** utilizando PCs conectados en LAN y Arduinos como nodos de control.

### Conexión en Estrella
Todos los nodos (PCs y Arduinos) están conectados a un nodo central (switch).  
Se probó el encendido y apagado de un LED en el Arduino desde cualquier PC, propagando la señal a los demás nodos.

<img width="493" height="146" alt="image" src="https://github.com/user-attachments/assets/fdb14e69-c719-45d8-a59d-c87cea7908cf" />

### Conexión en Árbol
El switch funcionó como nodo raíz, distribuyendo la comunicación en niveles jerárquicos.  
Se reenviaron lecturas desde el Arduino hasta un PC central.

<img width="452" height="257" alt="image" src="https://github.com/user-attachments/assets/a96bf182-781a-4781-92e2-fcf381bf8012" />

### Conexión en Anillo
Cada PC/Arduino se conectó formando un ciclo cerrado.  
Se implementó el concepto de **token**, donde solo el nodo que lo posee puede enviar datos al Arduino.

<img width="341" height="145" alt="image" src="https://github.com/user-attachments/assets/1dfeffba-cb9a-4409-86ef-edc496459de1" />

### Conexión Parcial
En este caso no todos los nodos tenían conexión directa.  
Se simuló la **caída de un nodo** y se observó el impacto en la red.

<img width="323" height="91" alt="image" src="https://github.com/user-attachments/assets/2df22ad1-18e7-41d8-aeee-b5602ac5610b" />

# Punto 3: Integración con GitHub

Todo el desarrollo correspondiente a los **Puntos 1 y 2** fue correctamente documentado y subido al repositorio del proyecto.  
Esto permitió mantener una estructura organizada y un control de versiones claro a lo largo de todo el proceso de laboratorio.

### Archivos incluidos en el repositorio
El repositorio contiene los siguientes elementos:

**Configuraciones del switch:**  
  Archivos con los comandos utilizados para la creación y gestión de VLANs, asignación de puertos y verificación de conectividad.  
  Estos archivos facilitan la replicación del entorno en otros dispositivos o simuladores.

**Programas de comunicación:**  
  Códigos desarrollados para la interacción entre **Arduinos** y **PCs**, tanto por conexión serial como a través de red local (LAN).  
  Se documentaron los protocolos de envío, la estructura de los paquetes y las pruebas realizadas.

**Archivo README:**  
  Documento principal del repositorio (este mismo archivo), que describe los objetivos, la estructura del proyecto y las instrucciones necesarias para ejecutar cada componente.

---

# Conclusiones

- La práctica permitió **comprender la configuración básica de un switch**, abarcando tanto la creación de VLANs como la verificación de conectividad entre dispositivos.  
- Se analizaron y compararon distintas **topologías de red**, observando su impacto en el desempeño y la latencia de comunicación.  
- La **integración de PCs y Arduinos** dentro de una misma red local destacó la importancia de los **protocolos estandarizados** (como TCP/IP y UART) para lograr interoperabilidad.  
- **GitHub** se empleó como **repositorio central** para el control de versiones, la colaboración y la documentación de los resultados obtenidos.  
- La implementación de un flujo de trabajo basado en **branches y commits** ayudó a mantener la trazabilidad y evitar conflictos entre diferentes versiones del código.  
- Este proceso también fomentó el uso de **buenas prácticas de documentación**, algo esencial en entornos colaborativos de ingeniería.


