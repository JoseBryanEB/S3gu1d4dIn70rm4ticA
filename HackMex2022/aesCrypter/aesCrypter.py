
lines= open("text.txt","r").readlines()
cadena = "0x00,0x11,"
for line in lines :
    l = line.split(" ")
    for a in l:
        if "h" in a:
            cadena+="0x"+str.strip(a.replace('h','').replace('0',''))+","
print (cadena)

lines= open("text2.txt","r").readlines()

cadena="E"
for line in lines:
    index = line.index("'")
    cadena+=line[index+1:index+2]
print (cadena)
