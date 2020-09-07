Para este reto de reversing se nos da un mensaje secreto 


m = 2E62DD6F7BE9BDB80322DBEF52ECA8360E4E9CDABDA85D0936683EB7CE41CE91E6CCDFA433C3BB3F

y se nos da un ejecutable llamado cr4\_modulue.exe

se analizo con ida-pro para ver el codigo fuente en ensamblador, se podia ver mediante 
la grafica un if para saber si habia recivido argumentos o no en forma de texto plano
si no habia recivido texto plano mandaba un mensaje recordando al usuario usar texto 
plano sin embargo cuando era texto plano pasaba por una funcion de encode para esto 
vimos dos opciones 

1. En la primera era hacer el codigo fuente que hiciera el algoritmo inverso sobre el mensaje secreto
2. La segunda un poco menos elegante pero facil de terminar, usar el programa para ver que caracteres 
   componen la flag encryptada 

code :


El programa agarra dos caracteres de la cadena encriptada y recorre todo ascci usando una cadena 
con la flag desencriptada, es facil de ver que se usa el segundo for del programa para encontrar 
el caracter que hiciera que fuera acompletando la candena "flag"

<img src = ""https://github.com/JoseBryanEB/S3gu1d4dIn70rm4ticA/blob/master/HackDef2020/cr4/result.png"/>
