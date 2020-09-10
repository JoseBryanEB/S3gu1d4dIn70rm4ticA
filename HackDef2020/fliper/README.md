# Flipper
Este reto se basa en econtrar la vulnerabilidad del CBC
se nos da un codigo en el cual se encuentra una funcion para desencriptar 
<code>         cipher = AES.new(bytes(key,"utf-8"),AES.MODE_CBC,iv) </ code > 
en esta linea se observa como usan el modo CBC para el encriptado de la bandera 

Checando en el internet encontre la siguiente pagina
<link href= "https://dr3dd.gitlab.io/cryptography/2019/01/10/simple-AES-CBC-bit-flipping-attack/"> AES CBC_ATAKK</link>

para resolverlo se hizo un script extremadamente corto en el cual se hace un socket para conectar con un servicio 
el problema esta en el codigo fuente el error es que el para el párametro iv siempre se usa una llave "AAAAAAAAAAAA"
cuando en esa llave en la posicion 7 contando del 0..7 agregar un 6, por como funciona el CBC al desencriptar lanza algo como 
<code > id=D </code > 
y al hacer lo contrario o sea poner el dato que salio en el id ahora metemos D en la posicion 7
y el resultado es id=6 y por lo tanto nos libera la flag
el funcionamiento es como el de un xor

6 es opuesto a un  caracter 
y por lo tanto si ingresas ese caracter te aparece su inverso, el 6 


