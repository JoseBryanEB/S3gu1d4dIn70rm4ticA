import socket 
host,port  = "18.221.44.9", 3133
socket = socket.socket()
socket.connect((host,port))
recivido = socket.recv (1024)
print (recivido,"\n")

recivido = socket.recv (1024)
print (recivido,"\n")
mes = input ("Mensaje")
socket.send(mes.encode("ascii"))

recivido = socket.recv (1024)
print (recivido,"\n")
mes = "AgfJA2rLzNTIyxnLnJrFm3nFzdnTnhmXngqWx2y0yZfSx3a0CJrFyZbTm256nhj9cG==" 
socket.send(mes.encode("ascii"))
recivido = socket.recv (1024)
print (recivido,"\n")
recivido = socket.recv (1024)
print (recivido,"\n")
