# jax 
es un caso especial ya que el programa traiia la repuesta este reversing practicamente era sobre corregir
el codigo y sacar la bandera
 
la clase Flag dentro del programa usaba una manera inusual de crear la banderal, tomaba el nombre del 
ususario de la pc, y el error selectIndexUndefined o sea una overflow de una cadena, 
y lo encriptaba el resultado de es cadena era la flag pero como el usuario cambiaba de pc en pc 
ya que lo toma de la pc al ejecurse, hubo un trabajo extra que hacer
encontrar el nombre del usuario que creo el programa, afortunadamente todo eso lo guarda .net 
haciendo un
 
<code> strings jax.exe </code> 

se encontro la cadena del workpace donde se desarrollo la aplicaión, pasando los parametros correctos y corrigiendo el programa 
sale la flag

<img src= "https://github.com/JoseBryanEB/S3gu1d4dIn70rm4ticA/blob/master/HackDef2020/jax/result.png" />
