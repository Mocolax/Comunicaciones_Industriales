# 9. Laboratorio RS485

# Mateo Gutierrez, Nicolas Alfonso, Julian Montealegre

## 1. Objetivo
Este laboratorio tiene como propósito implementar comunicación RS-485 con dos Arduino Uno, evaluando dos configuraciones del bus: simplex y full-duplex, usando dos y cuatro módulos MAX485, respectivamente. En la práctica, un Arduino enviará el valor leído desde un potenciómetro y el otro controlará un motor reductor tipo servo de forma proporcional. Durante las pruebas se medirán la tasa de paquetes, los errores y la estabilidad del enlace para comparar el comportamiento de ambas topologías.

## 2. Topologías y cableado
En todas las variantes se emplea par trenzado conectando A con A y B con B, con terminación de 120 Ω en los extremos del/los bus(es) y tierra común entre ambas placas y módulos. En los MAX485, la línea DE habilita la transmisión cuando está en alto y RE (o RE¯) habilita la recepción cuando está en bajo.

### 2.1 Simplex un solo bus
En modo simplex un Arduino actúa como transmisor y el otro como receptor, cada uno con un módulo MAX485. Se coloca una resistencia de 120 Ω entre A y B en cada extremo del bus y se comparte la tierra entre ambos sistemas. El transmisor (Arduino A) conecta D8 a DI, pone DE en alto y RE en alto; el receptor (Arduino B) conecta RO a D10 y mantiene DE y RE en bajo. La alimentación es de 5 V para ambos módulos, con sus respectivas masas comunes.

**Diagrama ascii**
```
Arduino A    MAX485          Bus RS485           MAX485      Arduino B
TX D8  --->  DI         A ---------------- A     RO ----> RX D10
GND   -----  GND        B ---------------- B     GND ---  GND
DE D2 -----  DE=alto                                      DE y RE a bajo
RE D3 -----  RE=alto
```

### 2.2 Full duplex dos buses
En modo full-duplex cada Arduino emplea dos MAX485: uno dedicado a transmitir y otro a recibir, formando dos buses independientes (uno para A→B y otro para B→A), cada cual con su terminación de 120 Ω en ambos extremos. En el Arduino A, el transmisor del Bus 1 conecta D8 a DI con DE en alto y RE en alto, mientras que el receptor del Bus 2 entrega RO a D10 manteniendo DE y RE en bajo. En el Arduino B se realiza la conexión recíproca: recibe por el Bus 1 (RO→D10 con DE y RE en bajo) y transmite por el Bus 2 (D8→DI con DE y RE en alto). Ambos buses comparten la misma referencia de tierra.

**Diagrama ascii**


Diagrama ascii
```
Bus uno  A  TX de Arduino A  ---> RX de Arduino B
Bus dos  B  TX de Arduino B  ---> RX de Arduino A

Arduino A
  TX bus uno   D8 -> DI   DE D2 alto   RE D3 alto
  RX bus dos   D10 <- RO  DE D4 bajo   RE D5 bajo

Arduino B
  RX bus uno   D10 <- RO  DE D4 bajo   RE D5 bajo
  TX bus dos   D8 -> DI   DE D2 alto   RE D3 alto
```


## 3. Procedimiento
Para simplex, se carga en el Arduino A el sketch emisor que lee el potenciómetro y envía tramas por RS-485, y en el Arduino B el sketch receptor que decodifica los datos y gobierna el servo. La verificación consiste en observar la recepción continua de las tramas y el movimiento proporcional del actuador respecto al valor del potenciómetro.

Para full-duplex, el Arduino A se configura como maestro que transmite el valor del potenciómetro por el Bus 1 y espera un acuse por el Bus 2; el Arduino B se configura como esclavo que recibe, actúa sobre el servo y envía la confirmación. La validación se realiza comprobando la concurrencia de transmisión y recepción y la coherencia entre el dato enviado y la respuesta recibida.

## 4. Resultados y análisis
Durante las pruebas se registran la tasa de paquetes, los errores y la respuesta del actuador. En caso de inestabilidad se recomienda ajustar el baudrate y revisar cuidadosamente las terminaciones hasta lograr un flujo estable y sostenido. También se documenta la sensibilidad frente a la longitud del cable y a posibles fuentes de ruido, comparando el comportamiento entre simplex y full-duplex.

## 5. Conclusiones
La estabilidad del bus está fuertemente condicionada por la topología y la terminación adecuadas. En simplex, la comunicación unidireccional ofrece suficiente desempeño para tareas de control simples con baja complejidad de hardware. En full-duplex, el uso de dos buses habilita confirmaciones y telemetría simultáneas, reduciendo latencia y mejorando la observabilidad, a costa de más módulos y mayor cableado.

## 6. Diferencias entre simplex y full duplex
En simplex se utiliza un solo bus y la transmisión ocurre en un único sentido; si ambos nodos necesitaran hablar, sería necesario coordinar turnos. En full-duplex se disponen dos buses que permiten transmisión y recepción simultáneas, lo cual incrementa el número de módulos y el cableado, pero reduce la latencia y facilita la gestión de acuses.

| Criterio | Simplex | Full duplex |
|---------:|---------|-------------|
| Buses | uno | dos |
| Módulos por arduino | uno | dos |
| Sentido de datos | unidireccional | bidireccional simultáneo |
| Complejidad | baja | media |
| Latencia | mayor | menor |

## 7. Visualización en tiempo real con dashboard
El repositorio incluye en la carpeta raíz el script dashboard_serial.py, con el que es posible graficar en tiempo real el valor del potenciómetro y el ángulo del servo. Para ejecutar el tablero se instalan las dependencias pyserial, streamlit y plotly, y luego se lanza el servidor local. En la propia interfaz se seleccionan el puerto y los baudios antes de iniciar la captura.


