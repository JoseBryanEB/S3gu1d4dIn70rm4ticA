lines = open("text.txt","r").readlines()
print (lines)
Flag= "";
for line in lines: 
    splits = line.split(" ")
    #print(splits)
    if "const" in splits[0]:
        print (splits[1]) 
        Flag+=str.strip(splits[1])+" ";
print (Flag)
