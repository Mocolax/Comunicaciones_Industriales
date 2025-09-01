from machine import Pin, I2C
import time

# Pines de los LEDs (GP10, GP11, GP12 en tu Pico 2 W)
led_pins = [Pin(10, Pin.OUT), Pin(11, Pin.OUT), Pin(12, Pin.OUT)]

# Configuración del bus I2C1 (SDA=GP2, SCL=GP3)
i2c = I2C(1, scl=Pin(3), sda=Pin(2), freq=100000)

# Dirección del Arduino
arduino_addr = 0x08

def show_binary(value):
    """Muestra los 3 bits en los LEDs"""
    for i in range(3):
        led_pins[i].value((value >> i) & 1)

while True:
    try:
        data = i2c.readfrom(arduino_addr, 1)   # Leer 1 byte del Arduino
        valor = data[0]
        print("Valor recibido:", valor)

        # Mostrar los 3 bits más significativos
        show_binary(valor >> 5)

        time.sleep(0.5)

    except Exception as e:
        print("Error I2C:", e)
        time.sleep(1)
