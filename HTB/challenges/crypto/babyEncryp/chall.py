import string

MSG = {ord('F')}  # 00-FF
m = "6e0a9372ec49a3f6930ed8723f9df6f6720ed8d89dc4937222ec7214d89d1e0e352ce0aa6ec82bf622227bb70e7fb7352249b7d893c493d8539dec8fb7935d490e7f9d22ec89b7a322ec8fd80e7f8921"
def encryption(msg):
    ct = []
    for char in msg:
        ct.append((123 * char + 18) % 256) #((89*123)+18)%256
    return bytes(ct)

ct = encryption(MSG)
x=0
flag=""
for c in m:
    if (x+1)>len(m):
        break
    o = bytes({(int(m[x:x+2],16))})
    x=x+2
    for i in range(0,256):
        ct = encryption([i])
        #print (ct)
        if ct == o: # cipher['O'] -> new_cipher['O']  o
            #   print ("ct: ",ct)
            #print ("o: ", o)
            flag=flag +chr (i)
            break

print (flag)
#print (flag2)
