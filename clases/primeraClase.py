#comentario de una linea
"""
comentario 
de 
varias 
lineas
"""
#strings
'string'
"string"
#estructuras de control
"""
while condiciones : 
    code

for i in range(0,10):
    code

if (condicion): 
    code

if (condicion):
    codigo
elif (condicion):
    codigo
else if (condicion):
    codigo
else :
    codigo

"""

#primer programa 0 - 100 
"""
i =0 
while i<=100 : 
    print(i)
    i+=1

for i in range (0,101): #0-100
    print(i)

for i in range(101):
    print(i)

i = 0
i = "string"

import os
import numpy as np
from pandas import interables as pi
from CTF import flag
"""
string = "algo"
for char in string:
    print(chr(ord(char)^0x20))

string = "mov eax 0x34"
splitString = string.split(" ")
print (splitString)
for c in splitString: 
    print (c)

lista = ['a',100,'aas',100,100.23]
print ( lista)
for c in lista: 
    print (c)
        # 0   1   2     3    4
        #-5   -4   -3     -2    -1
lista = ['a',100,'aas',100,100.23]
print(lista[0])
print ("con negativos")
for i in range (-1,-6,-1):
    print (lista[i])

#slice
print (lista[0:-1])

izq = lista[0:len(lista)//2]
der = lista[len(lista)//2:]
print (izq)
print (der)

print (str(3))
print (int("3"))
print (int("3",16))

dic = {"a":'b','b':'a','c':102,1:'1'}
for a in dic.items(): 
    print (a)
    #print('key: '+str(key)+' val:'+str(val))

for a in dic: 
    dic[a]=100;
    print(dic[a])

for key,val in dic.items(): 
    print('key: '+str(key)+' val:'+str(val))
dic ['h']=30
print (dic.items())
a,b = ['a','b']

tupla = (1,25)
uno,dos = tupla
print (tupla)
print (uno,dos)
print (a,b)
