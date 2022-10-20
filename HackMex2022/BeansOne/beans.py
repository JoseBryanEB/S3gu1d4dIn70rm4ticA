lines = open("texto.txt","r").readlines()
string = ""
cont =0; 
for line in lines : 
    if ";" in line: 
        cont+=1
        string += line.split(";")[1].split(" ")[1].split('\n')[0]

print (string)
#print (cont)