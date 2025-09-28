# Arbol middle => Receives from Arduino and sends through Ethernet
import socket
import serial
import time

arduino = serial.Serial('COM17', 9600)

try:
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect(('192.168.1.20', 5000))  # IP del servidor

    while True:
        data = arduino.read()  # pide 1 byte
        valor=int.from_bytes(data)
        print("Recibí:", valor)
        client.send(data)

except KeyboardInterrupt:
    client.close()
    arduino.close()