# 🧩 Configuración y Verificación de VLANs

---

## 📸 Evidencias iniciales

<p align="center">
  <img src="./evidencia1_1.jpg" width="45%">
  <img src="./evidencia1_2.jpg" width="45%"><br>
  <img src="./evidencia1_3.jpg" width="45%">
  <img src="./evidencia1_4.jpg" width="45%"><br>
  <img src="./evidencia1_5.jpg" width="45%">
  <img src="./evidencia1_6.jpg" width="45%">
</p>

---

## 🎯 1. Objetivo del laboratorio
Configurar una red segmentada mediante **VLANs (Virtual Local Area Networks)** y verificar su correcto funcionamiento a través de pruebas de **ARP, IP, conectividad y estructura de red**.  
El propósito fue **aislar el tráfico entre grupos de dispositivos**, garantizando que cada VLAN operara como una red independiente dentro de la misma infraestructura física.

---

## ⚙️ 2. Equipos y topología utilizada
Se utilizó un **router de capa 3**, **dos switches de capa 2** y varios **dispositivos finales (PCs)** conectados a diferentes puertos físicos.  
En condiciones ideales, se conectaron **dos PCs por cada switch**, pero por disponibilidad de equipos, una VLAN contó con un solo PC.

---

## 🔧 3. Configuración del router y los switches
- En el **router**, se configuraron los parámetros básicos para permitir la gestión y el direccionamiento.  
- En los **switches**, se crearon dos VLANs independientes para segmentar el tráfico.  
- Cada VLAN utilizó una dirección del tipo `192.168.x.1` con máscara `255.255.255.0`.  
- Se habilitaron los puertos necesarios y se asignaron correctamente a cada VLAN.  

**Objetivo:** asegurar comunicación interna dentro de cada VLAN y aislamiento entre VLANs diferentes.

---

## 🧠 4. Verificación de la VLAN 1
- Se verificaron las direcciones IP asignadas a los dispositivos.  
- Se realizaron pruebas de conectividad mediante `ping` dentro de la VLAN.  
- Se ejecutó `arp -a` para comprobar la tabla ARP, confirmando la resolución de direcciones IP–MAC.  
- Los resultados mostraron comunicación exitosa entre dispositivos del mismo dominio de broadcast.

---

## 🧠 5. Verificación de la VLAN 2
- Se repitieron las pruebas de IP, ping y ARP.  
- Los equipos dentro de la VLAN 2 se comunicaron correctamente.  
- Los intentos de ping entre VLANs fallaron, comprobando el aislamiento esperado.  
- Las tablas ARP y las direcciones MAC se registraron correctamente en el switch.

---

## 🕸️ 6. Comprobación de la arquitectura y la topología de red
Se verificó una **topología jerárquica**:
- El **router** operó como dispositivo de **capa 3**, encargado del enrutamiento entre VLANs.  
- Los **switches** actuaron como dispositivos de **capa 2**, responsables de la segmentación.  

El análisis de **puertos, IPs, ARP y conectividad** validó que la red estaba correctamente implementada y operativa.

---

## 🖥️ VLAN 1

<p align="center">
  <img src="./Vlan1_1.png" width="45%">
  <img src="./Vlan1_2.png" width="45%">
</p>

---

## 🖥️ VLAN 2

<p align="center">
  <img src="./Vlan1_2.png" width="45%">
  <img src="./Vlan2_2.png" width="45%">
</p>

---

## 🧩 Otras configuraciones

<p align="center">
  <img src="./otros1_1.png" width="45%">
  <img src="./otros1_2.png" width="45%"><br>
  <img src="./otros1_3.png" width="45%">
  <img src="./otros1_4.png" width="45%">
</p>

---

## ✅ 7. Conclusión

La configuración de las **VLANs** permitió segmentar efectivamente la red, reduciendo el dominio de broadcast y mejorando el control del tráfico.  
Las pruebas con **IP, ARP y ping** confirmaron que los dispositivos dentro de una misma VLAN se comunicaban entre sí, mientras que los de VLANs distintas permanecían aislados.  

La **topología y la arquitectura** implementadas cumplieron con los objetivos del laboratorio, validando una correcta segmentación y funcionamiento de la red.

---
