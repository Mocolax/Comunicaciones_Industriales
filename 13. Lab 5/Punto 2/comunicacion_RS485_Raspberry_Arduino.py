# ===========================================================
# Comunicación RS485 entre Raspberry Pi y Arduino
# Control independiente de DE (GPIO17) y RE (GPIO18)
# Puerto serial /dev/serial0 a 9600 baudios
# ===========================================================

import serial
import RPi.GPIO as GPIO
import time

# =========================================
# Configuración de pines GPIO
# =========================================
DE_PIN = 17   # Pin físico 11
RE_PIN = 18   # Pin físico 12

GPIO.setmode(GPIO.BCM)
GPIO.setup(DE_PIN, GPIO.OUT)
GPIO.setup(RE_PIN, GPIO.OUT)

# =========================================
# Inicialización del puerto serial
# =========================================
# El puerto puede ser /dev/serial0 o /dev/ttyAMA0 según la versión del sistema
ser = serial.Serial(
    port='/dev/serial0',
    baudrate=9600,
    timeout=1
)

# =========================================
# Funciones de control
# =========================================
def enable_tx():
    """Activa modo transmisión (DE=HIGH, RE=HIGH)."""
    GPIO.output(DE_PIN, GPIO.HIGH)
    GPIO.output(RE_PIN, GPIO.HIGH)
    time.sleep(0.01)

def enable_rx():
    """Activa modo recepción (DE=LOW, RE=LOW)."""
    GPIO.output(DE_PIN, GPIO.LOW)
    GPIO.output(RE_PIN, GPIO.LOW)
    time.sleep(0.01)

# =========================================
# Bucle principal
# =========================================
try:
    print("Iniciando comunicación RS485...")
    enable_rx()

    while True:
        # Activar transmisión
        enable_tx()
        mensaje = "Hola desde Raspberry Pi\n"
        ser.write(mensaje.encode('utf-8'))
        print("Enviado:", mensaje.strip())

        # Volver a modo recepción
        enable_rx()
        time.sleep(0.5)

        # Si hay datos recibidos
        if ser.in_waiting:
            recibido = ser.readline().decode('utf-8').strip()
            if recibido:
                print("Recibido:", recibido)

        time.sleep(1)

# =========================================
# Manejo de salida
# =========================================
except KeyboardInterrupt:
    print("\nFinalizando programa...")
    ser.close()
    GPIO.cleanup()
    print("Puerto serial cerrado y GPIO liberados.")
