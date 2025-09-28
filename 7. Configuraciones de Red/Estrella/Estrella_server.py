# Servidor
import socket
import serial

arduino = serial.Serial('COM6', 9600)

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('0.0.0.0', 5000))
s.listen()

print("Esperando conexión...")
conn, addr = s.accept()
print("Conectado desde", addr)
try:
    while True:
        data = conn.recv(1)  # pide 1 byte
        print("Recibí:", data)
        arduino.write(data)

except KeyboardInterrupt:
    conn.close()
    s.close()
    arduino.close()