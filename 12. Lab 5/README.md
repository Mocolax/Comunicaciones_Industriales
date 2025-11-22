# Laboratorio 5: Comunicación Industrial y Control con PLC
Gutiérrez Mateo – Cód. 2334475
Alfonso Rodríguez Nicolás David – Cód. 2303507
Montealegre Julián – Cód. 2343485

Este laboratorio tuvo como propósito integrar diferentes niveles de
comunicación industrial, desde la conexión básica de una red local,
hasta la interacción entre sistemas embebidos mediante el protocolo
Modbus RTU y la programación de un PLC Siemens utilizando TIA Portal y
PLCSIM.\
El trabajo permitió comprender cómo se relacionan las redes de
comunicación, los buses industriales y el control lógico programable
dentro de un entorno de automatización.

------------------------------------------------------------------------

## Punto 1. Prueba de una red sencilla

En esta primera parte se realizó la configuración y verificación de una
red local básica.\
Se estableció la conexión entre los diferentes dispositivos ---como la
Raspberry Pi, el computador, el router y el switch--- con el objetivo de
entender la estructura física y lógica de una red de comunicación.\
Durante la práctica se revisaron direcciones IP, tablas ARP y la
arquitectura de red, con el fin de asegurar la correcta comunicación
entre los equipos.\
Esta experiencia permitió reconocer el papel que cumple cada elemento en
la red: el router como dispositivo de direccionamiento, el switch como
distribuidor local y los equipos terminales como nodos de intercambio de
información.\
Al finalizar, se verificó la conectividad mediante pruebas de
comunicación, comprobando que todos los dispositivos estaban
correctamente enlazados dentro de la misma topología.

------------------------------------------------------------------------

## Punto 2. Comunicación RS-485 entre Raspberry Pi y Arduino (Modbus RTU)

El segundo punto se centró en establecer una comunicación industrial
basada en el protocolo Modbus RTU sobre el estándar físico RS-485, entre
una Raspberry Pi y un dispositivo esclavo, representado por un Arduino o
un PLC.\
Esta práctica tuvo como objetivo demostrar cómo un sistema maestro puede
leer o escribir datos en un dispositivo remoto utilizando un medio
diferencial confiable y robusto, común en entornos industriales.

Para lograrlo, se preparó la Raspberry Pi como maestro Modbus,
configurando sus parámetros de comunicación serial y enlazándola
físicamente mediante un convertidor RS-485 o módulo MAX485.\
Se abordaron conceptos como la paridad, la velocidad de transmisión y la
estructura del mensaje Modbus.\
Durante la simulación, la Raspberry Pi solicitó datos al esclavo,
confirmando la correcta transmisión y recepción de información.

El ejercicio permitió observar la estabilidad y precisión de la
comunicación Modbus RTU, además de comprender cómo se organiza el
intercambio de registros y cómo este protocolo es utilizado en la
industria para la supervisión de sensores, actuadores y controladores
programables.

------------------------------------------------------------------------

## Punto 3. Prueba de PLC: Encendido y apagado de una lámpara virtual

Finalmente, se desarrolló una práctica de control utilizando un **PLC
Siemens S7-1200** programado en el entorno **TIA Portal**, con
simulación en **PLCSIM**.\
El objetivo fue crear un programa sencillo que encendiera y apagara una
lámpara virtual a partir de la acción de un botón digital.\
Dentro del entorno de programación se configuró una entrada digital para
el botón (I0.0) y una salida digital para la lámpara (Q0.0).\
Posteriormente, se elaboró el diagrama en lenguaje Ladder (KOP), en el
cual un contacto controla una bobina que representa la salida.

Una vez cargado el programa al simulador, se probó el funcionamiento
activando la entrada virtual, observando cómo la salida se activaba de
forma inmediata.\
Esta experiencia permitió comprender el proceso completo de creación de
un proyecto en TIA Portal, desde la configuración de la CPU, la
asignación de direcciones y la elaboración del programa, hasta la
simulación final con PLCSIM.

Con esta práctica se consolidaron conceptos fundamentales sobre
direccionamiento de entradas y salidas, lógica Ladder y carga de
programas, aplicados a un caso de control elemental.

------------------------------------------------------------------------

## Conclusiones

El laboratorio permitió articular tres niveles de conocimiento dentro
del campo de la automatización industrial: la **comunicación en redes**,
la **interconexión mediante protocolos industriales** y la
**programación de controladores lógicos programables**.\
A través de estas actividades se fortaleció la comprensión del flujo de
información desde la capa física hasta el nivel de control, destacando
la importancia de la correcta configuración, direccionamiento y
verificación de cada sistema involucrado.\
Asimismo, se evidenció la utilidad de herramientas como Modbus RTU y TIA
Portal para implementar y simular procesos de automatización de manera
práctica y didáctica.

