import socket
socket = socket.socket()
host , port = "3.19.72.219",3166
socket.connect((host,port))

mes= socket.recv(1024)
print (mes,"\n")
mes= socket.recv(1024)
print (mes,"\n")
enviar = input("enviar")
socket.send(enviar.encode("ascii"))   

while True: 
    mes= socket.recv(1024)
    print (mes,"\n")
    enviar = input("enviar")
    socket.send(enviar.encode("ascii"))  
    mes= socket.recv(1024)
    print (mes,"\n")
    enviar = "AAAAAAA"+input("char" )+"AAAAAAAAAAAAA"
    socket.send(enviar.encode("ascii"))  
    mes= socket.recv(1024)
    print (mes,"\n")
    mes= socket.recv(1024)
    print (mes,"\n")
    enviar = input("enviar")
    socket.send(enviar.encode("ascii"))  