import subprocess

flag = "hackdef" # la pasamos la variable
flagCript = "2E62DD6F7BE9BDB80322DBEF52ECA8360E4E9CDABDA85D0936683EB7CE41CE91E6CCDFA433C3BB3F"
for a in range ((len(flag)-1)*2,len(flagCript)-1):
    token = (flagCript[a:a+2])
    for x in range (33,255): 
        p = subprocess.Popen("C:\\Users\\Slayer\\Documents\\hackdef4cr\\C2C_module.exe "+str(flag+chr(x)), stdout=subprocess.PIPE, shell=True)
        (output, err) = p.communicate()
        p_status = p.wait()
        value = str (output,"ascii")
        if value == flagCript[0:a+2]:
            print(flag) 
            flag+= chr(x)
            break
        
   #hackdef{RC4_is_c0mm0nly_used_by_m4lwar3} 