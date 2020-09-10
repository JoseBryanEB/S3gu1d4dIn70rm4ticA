# fisgon 
este reto tiene una vulnerabilidad bien conocida como xss atack que basicamente permite incrustar tu propio codigo 
fuente ya sea en html o en javascript. 

El problema basicamente pedia recibir la contraseña del admin que ingresaba cada 10 min aprox 
se utilizo depues de varios intentos con parametros get (Admin, contraseña), se intento ya al final practicamente 
un keylogger esperamos que el usuario se conecte y listo
el problema es que el keylogger agrego algunos caracteres de la distribucion de teclado americana (US)
cambiando los $ por _ 

<img src="https://github.com/JoseBryanEB/S3gu1d4dIn70rm4ticA/blob/master/HackDef2020/xss/result.png"/>

