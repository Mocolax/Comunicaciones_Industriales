# Laboratorio 3
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

