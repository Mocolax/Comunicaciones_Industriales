# Vigilancia tecnológica de protocolos industriales

# Mateo Gutierrez, Nicolas Alfonso, Julian Montealegre

---

## 1. Modbus

### ¿Qué es?
- Protocolo de comunicación industrial creado por Modicon, ahora Schneider Electric, en 1979
- Usado para conectar PLC, sensores y actuadores en redes industriales

### ¿Para qué sirve?
- Transmisión de datos entre dispositivos bajo arquitectura maestro–esclavo
- Integración entre sistemas SCADA y equipos de campo

### Características o tipos
- Modbus RTU, Modbus ASCII y Modbus TCP/IP
- Comunicación serie RS-232 y RS-485, y sobre Ethernet
- Estructura de mensajes sencilla
- Comunicación determinista y confiable

### Ventajas
- Estándar abierto y gratuito
- Fácil de implementar y diagnosticar
- Alta compatibilidad entre fabricantes

### Desventajas
- Velocidad limitada en versiones serie
- Sin seguridad integrada
- Comunicación unidireccional maestro–esclavo

---

## 2. AS-Interface o AS-i

### ¿Qué es?
- Sistema de comunicación para conectar sensores y actuadores a controladores superiores
- AS-Interface se conoce como Actuator Sensor Interface

### ¿Para qué sirve?
- Reduce el cableado entre dispositivos de campo y controladores mediante un único cable plano de dos hilos que transporta energía y datos

### Características o tipos
- Topología libre: estrella, anillo, árbol o línea
- Comunicación maestro–esclavo
- Distancia máxima de 100 m ampliable con repetidores
- Hasta 62 dispositivos por red

### Ventajas
- Instalación rápida y económica
- Cableado reducido con energía y datos en el mismo cable
- Pasarelas disponibles hacia PROFIBUS, PROFINET y Modbus

### Desventajas
- Enfocado al nivel de campo
- Ancho de banda reducido
- No apto para tiempos de respuesta extremadamente cortos

---

## 3. Ethernet industrial

### ¿Qué es?
- Adaptación robusta de Ethernet para entornos industriales
- Orientado a alta velocidad, seguridad y comunicación en tiempo real

### ¿Para qué sirve?
- Interconexión de controladores, sensores, robots y sistemas SCADA con sincronización precisa en planta

### Tipos o categorías principales
- PROFINET
- EtherNet/IP
- EtherCAT
- Powerlink
- Modbus TCP
- CC-Link IE

### Ventajas
- Altas velocidades de transmisión hasta nivel de gigabits
- Integración con redes de tecnología de la información empresariales
- Soporte para comunicación en tiempo real
- Escalabilidad y flexibilidad

### Desventajas
- Mayor costo de implementación
- Requiere hardware compatible
- Configuración más compleja

---

## 4. Direccionamiento IP en redes industriales y de planta


### ¿Qué es IPv4?

**IPv4 (Internet Protocol version 4)** es la cuarta versión del Protocolo de Internet (IP) y la más utilizada históricamente para la comunicación en redes.  
Fue diseñada para identificar dispositivos mediante una dirección única de **32 bits**, lo que permite aproximadamente **4.3 mil millones de direcciones** diferentes.

#### 🔹 Características de IPv4
- Usa **32 bits**, divididos en **cuatro octetos** separados por puntos (por ejemplo, `192.168.1.1`).
- Soporta **clases de direcciones** (A, B, C, D, E) y actualmente usa **CIDR (Classless Inter-Domain Routing)**.
- Permite **asignación manual o automática** mediante DHCP.
- Utiliza **broadcast** para enviar mensajes a todos los dispositivos de una red.
- Puede usar **NAT (Network Address Translation)** para compartir una sola dirección pública entre varios dispositivos.
- Seguridad mediante **IPSec**, pero es **opcional**.

---

### ¿Qué es IPv6?

**IPv6 (Internet Protocol version 6)** es la versión más reciente del Protocolo de Internet, creada para reemplazar a IPv4 debido al agotamiento de direcciones.  
Utiliza direcciones de **128 bits**, lo que permite una cantidad prácticamente ilimitada de direcciones únicas.

#### 🔹 Características de IPv6
- Usa **128 bits**, escritos en formato **hexadecimal** y separados por dos puntos (por ejemplo, `2001:0db8:85a3::8a2e:0370:7334`).
- No utiliza clases, sino **prefijos** para identificar tipos de redes.
- Posee **autoconfiguración automática (SLAAC)** y soporte para **DHCPv6**.
- No usa **broadcast**, sino **multicast** y **anycast**.
- Tiene **IPSec integrado** de manera nativa, aumentando la seguridad.
- Mejora la **calidad de servicio (QoS)** mediante los campos *Traffic Class* y *Flow Label*.
- No requiere **NAT**, gracias a su amplio espacio de direcciones.

---

### Tipos de direcciones IPv4 

- **Unicast**  
  - Dirección única a un solo host (ej.: `192.0.2.1`).  
  - Uso: comunicación punto a punto (host ↔ host).  

- **Broadcast**  
  - Dirección que entrega un paquete a *todos* los hosts de la subred.  
  - Ejemplo: `192.168.1.255` (broadcast de la subred `192.168.1.0/24`).  
  - Uso: descubrimiento y anuncios en la LAN (ARP, DHCP en algunos casos).

- **Multicast**  
  - Envío a un *grupo* de receptores interesados, no a todos.  
  - Rango: `224.0.0.0` – `239.255.255.255`.  
  - Uso: streaming, protocolos de control de red, descubrimiento de servicios.

- **Anycast (poco usado en IPv4)**  
  - Misma dirección asignada a múltiples nodos; el paquete es entregado al nodo "más cercano" según la topología de enrutamiento.  
  - Uso: balanceo y distribución de servicios, aunque es más habitual en IPv6.

- **Especiales / Reservadas**  
  - `0.0.0.0` → Dirección no especificada (inicio de DHCP, rutas).  
  - `127.0.0.0/8` → Loopback (ej.: `127.0.0.1`).  
  - `169.254.0.0/16` → Enlace local (APIPA) cuando no hay DHCP.  
  - `255.255.255.255` → Broadcast limitado.

---

### Tipos de direcciones IPv6 

- **Unicast**  
  - Direcciones para un único interfaz. Las hay de varios subtipos:  
    - **Global Unicast (GUA)**: `2000::/3` → direcciones públicas en Internet.  
    - **Unique Local (ULA)**: `fc00::/7` → similar a privadas en IPv4 (`10.x.x.x`), para redes internas.  
    - **Link-Local**: `fe80::/10` → sólo en el mismo enlace / segmento físico; usadas para autoconfiguración, vecindario y descubrimiento.  
    - **Loopback**: `::1/128` → pruebas locales.

- **Multicast**  
  - Prefijo `ff00::/8`. IPv6 usa multicast para reemplazar la difusión.  
  - Ejemplos de usos: Neighbor Discovery (ND), protocolos de routing, servicios de grupo.  
  - Los paquetes multicast tienen identificadores de alcance (link-local, site-local, global, etc.).

- **Anycast**  
  - Asignación de la misma dirección unicast a múltiples interfaces en diferentes nodos.  
  - El tráfico se enrutará al "mejor" nodo según la topología.  
  - Uso: balanceo de servicios, servidores de borde, CDN internos.

- **Unspecified**  
  - `::/128` → usada cuando no se ha asignado dirección (por ejemplo, antes de realizar SLAAC).

---

### Diferencias clave entre IPv4 e IPv6
- Longitud de dirección: IPv4 usa 32 bits y IPv6 usa 128 bits
- Formato: IPv4 en decimal con puntos y IPv6 en hexadecimal con dos puntos y abreviaciones
- Espacio de direcciones: IPv4 ofrece unos cuatro mil millones y IPv6 ofrece un espacio masivo
- Configuración: IPv4 con asignación manual o DHCP y IPv6 con autoconfiguración sin estado SLAAC y DHCPv6
- Seguridad: IPv4 con IPSec opcional e IPv6 con IPSec integrado en el protocolo
- Fragmentación: en IPv4 los routers pueden fragmentar y en IPv6 solo el emisor realiza fragmentación con descubrimiento de MTU
- Difusión: IPv4 usa broadcast e IPv6 elimina broadcast y usa multicast y anycast
- Calidad de servicio: IPv4 con campo TOS e IPv6 con Traffic Class y Flow Label
- NAT: común en IPv4 y poco necesario en IPv6 por el gran espacio de direcciones
- Transición: uso de doble pila y tecnologías de traducción y túneles

### Clases de IPv4 y rangos
> Nota técnica: hoy se usa CIDR, sin embargo estas clases siguen siendo material de estudio

| Clase | Rango inicial   | Rango final       | Máscara por defecto | Uso principal                  |
|------:|------------------|-------------------|---------------------|--------------------------------|
| A     | 0.0.0.0          | 127.255.255.255   | 255.0.0.0           | Redes muy grandes              |
| B     | 128.0.0.0        | 191.255.255.255   | 255.255.0.0         | Redes medianas                 |
| C     | 192.0.0.0        | 223.255.255.255   | 255.255.255.0       | Redes pequeñas                 |
| D     | 224.0.0.0        | 239.255.255.255   | N A                 | Multicast                      |
| E     | 240.0.0.0        | 255.255.255.255   | N A                 | Experimental y reservado       |

Rangos privados más usados
- 10.0.0.0 barra 8
- 172.16.0.0 barra 12
- 192.168.0.0 barra 16

Direcciones especiales de referencia
- 127.0.0.1 loopback
- 169.254.0.0 barra 16 enlace local

### Tipos de direcciones en IPv6 y prefijos comunes
> IPv6 no usa clases. Se organiza por prefijos y tipos de dirección

| Tipo               | Prefijo      | Uso principal                          |
|--------------------|--------------|----------------------------------------|
| Global unicast     | 2000:: barra 3   | Direccionamiento en Internet              |
| Unique local ULA   | fc00:: barra 7   | Redes privadas y sitios sin ruteo público |
| Link local         | fe80:: barra 10  | Comunicación en el mismo enlace           |
| Multicast          | ff00:: barra 8   | Grupos de difusión selectiva              |
| Anycast            | sin prefijo único| Mismo IP en múltiples nodos               |
| Loopback           | ::1 barra 128    | Pruebas locales                           |
| Unspecified        | :: barra 128     | Dirección no especificada                 |

Prefijos prácticos
- barra 64 para subredes de hosts
- barra 48 o barra 56 para asignación a organizaciones por proveedor
- mapeo IPv4 a IPv6 con prefijo ::ffff:0:0 barra 96 en integraciones

---

## Comparación general

| Protocolo            | Tipo de comunicación | Nivel de aplicación     | Ventajas principales                         | Desventajas principales            |
|----------------------|----------------------|-------------------------|----------------------------------------------|------------------------------------|
| Modbus               | Serie y Ethernet     | Control y supervisión   | Estándar abierto, implementación sencilla    | Velocidad limitada, sin seguridad  |
| AS-Interface         | Cable plano dos hilos| Nivel de campo          | Instalación simple y de bajo costo           | Limitado en velocidad y distancia  |
| Ethernet industrial  | Ethernet IP          | Planta y empresa        | Alta velocidad, integración con TI           | Costo y configuración más compleja |
