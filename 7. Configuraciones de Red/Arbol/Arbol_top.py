# Servidor
import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('0.0.0.0', 5000))
s.listen()

print("Esperando conexión...")
conn, addr = s.accept()
print("Conectado desde", addr)
try:
    while True:
        data = conn.recv(1)  # pide 1 byte
        valor=int.from_bytes(data,byteorder='little')
        print("Recibí:", valor)


except KeyboardInterrupt:
    conn.close()
    s.close()