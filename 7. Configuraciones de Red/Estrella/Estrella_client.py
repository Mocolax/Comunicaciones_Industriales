import socket

c = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
c.connect(('192.168.1.103', 5000))  # IP del servidor

print("Conectado al servidor. Escribe algo y presiona Enter. Ctrl+C para salir.")

try:
    while True:
        msg = input("> ")  # lo que digites
        if not msg:        # si mandas vacío, no enviamos nada
            continue
        c.send(msg.encode())  # manda los bytes

except KeyboardInterrupt:
    c.close()

