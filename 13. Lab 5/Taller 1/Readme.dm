# Configuración y Verificación de VLANs



### 1. Objetivo del laboratorio
El objetivo del laboratorio fue configurar una red segmentada mediante VLANs (Virtual Local Area Networks) y verificar su correcto funcionamiento a través de pruebas de ARP, IP, conectividad y estructura de red.
Con esta práctica se buscó aislar el tráfico entre grupos de dispositivos y garantizar que cada VLAN operara como una red independiente dentro de la misma infraestructura física.
### 2. Equipos y topología utilizada
Se utilizó un router de capa 3, dos switches de capa 2 y varios dispositivos finales (PCs) conectados a diferentes puertos físicos.
En condiciones ideales, se conectaron dos PCs por cada switch, pero debido a la disponibilidad de equipos, en una de las VLAN se utilizó únicamente un PC.
### 3. Configuración del router y los switches
En el router, se configuraron los parámetros básicos para permitir la gestión y el direccionamiento de red.
En los switches, se crearon y configuraron dos VLANs independientes con el fin de segmentar el tráfico.
Cada VLAN se configuró con una dirección de red del tipo 192.168.x.1 y una máscara de subred 255.255.255.0.
Además, en cada switch se habilitaron todos los puertos necesarios para la conexión de los equipos finales, asegurando la correcta asignación de puertos a cada VLAN.
El propósito de esta configuración fue garantizar que los dispositivos dentro de una misma VLAN pudieran comunicarse entre sí, mientras que los de VLANs distintas permanecieran aislados.
### 4. Verificación de la VLAN 1
En la VLAN 1, se revisaron las direcciones IP asignadas a los dispositivos para confirmar que pertenecieran a la misma subred.
Posteriormente, se ejecutaron pruebas de conectividad mediante el comando ping, verificando que los equipos dentro de la VLAN pudieran comunicarse correctamente entre sí.

También se utilizó el comando arp -a para comprobar la tabla ARP de cada dispositivo, observando las asociaciones entre direcciones IP y MAC.
Esto permitió confirmar que la resolución de direcciones funcionaba correctamente y que los dispositivos respondían dentro del mismo dominio de broadcast.
### 5. Verificación de la VLAN 2
Se repitió el mismo procedimiento para la VLAN 2.
Primero se verificó la configuración IP de los dispositivos conectados y luego se realizaron pruebas de ping para validar la conectividad interna.
Los resultados mostraron comunicación exitosa entre los equipos de la misma VLAN.
Además, se intentó realizar ping entre dispositivos de VLANs diferentes, comprobando que no existía comunicación entre ellas, lo cual evidenció la correcta segmentación de la red.
Finalmente, se revisaron las tablas ARP y las direcciones MAC para asegurar que las interfaces estaban correctamente registradas en el switch.
### 6. Comprobación de la arquitectura y la topología de red
Una vez verificadas las VLANs, se analizó la topología de red implementada.
Se confirmó que la estructura seguía un modelo jerárquico, donde el router funcionaba como dispositivo de capa 3 encargado del enrutamiento (en caso de necesitar comunicación entre VLANs) y los switches actuaban como dispositivos de capa 2 responsables de la segmentación.
La revisión general del estado de los puertos, direcciones IP, tablas ARP y conectividad validó que la red estaba correctamente implementada y operativa.







## Vlan1 




## Vlan2 






## otras configuraciones



 



      

### 7. Conclusión

La configuración de las VLANs permitió segmentar efectivamente la red, reduciendo el dominio de broadcast y mejorando el control del tráfico.
Las pruebas realizadas con IP, ARP y ping demostraron que los dispositivos dentro de una misma VLAN podían comunicarse entre sí, mientras que aquellos en VLANs diferentes permanecieron aislados.

El análisis de la topología confirmó que la red se estructuró correctamente y que la comunicación siguió las reglas de segmentación establecidas, cumpliendo los objetivos del laboratorio.
