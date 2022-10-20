from Crypto.PublicKey import RSA
from base64 import b64decode
import numpy as npobject
from Crypto.Util.number import long_to_bytes
from numpy import int8
from decimal import Decimal

key64 = b"MIICIjANBgkqhkiG9w0BAQEFAAOCAg8AMIICCgKCAgEAnorhURM7Y5MM42Khudar\
    4KMlkU2mDft5GzJ5bmKhktauv6Bs5s+XnDlgQLon61IFn6sqIT3lH7emviczsrVo\
    WZDBnhkKMstZxIkRTLuaT43Nqf87gwbUyAgD4FgW1lgVTeauo/bii2YYe6Wiv8iH\
    AKJLO1vMhcc4mnZ2gk5at7JSXsiASviFb/+G3gIHIWiM0vnt+cg2CR8JXAZc8WWp\
    c0TAAvWupjRR8v6pdyHgPnz+zXovdksmjoXkYcQ2Kz7UJh22UQZUZWKjqoZoXjQp\
    CB+BOaTJCWr6SkLlvFcg2+5dPN/S0Qio+YxLOnh6vUamF2L0PGbcKBQk2mTbRglA\
    Aw6VRTnTIKQ3DME5dPctaGgbeqDhLVr19/qcFrjKduQmkLIODU3Jg3KPq8Kn4OVT\
    rCb3L1Jp/dmR676j5m1geup+8yhnzbd3LoixamqcQRX89D+uHplinZ8Hc1gXCAfH\
    ceB6ih7uHWpO8AYCGGy5QyQyJIjOYGb1hZe+4tAcoV8gMGkxx8cnEie0EfjtdH/7\
    x1pJdESwVcl+D7mDWg14R5tn8nCbFCoXAQX5vbx+eBJqG3cDt3B3nWTDiOqDPqw/\
    Cu2bCSQulenSh8+XEWdsem4W2VigkeVKgSUsCGXK5j++8/3qZjJZl1Gc447H7eb4\
    9Ke054Tt9HzzwJx1mwzu1+UCAwEAAQ=="

from math import gcd

def phi(n):
    amount = 0        
    for k in range(1, n + 1):
        if gcd(n, k) == 1:
            amount += 1
    return amount    

keyDER = b64decode(key64)
SECRET_KEY = RSA.importKey(keyDER)
#print (SECRET_KEY.n)
data = open("output.txt","r")
data=data.readlines()[0];
data = data.replace("]","")
data = data.replace("[","")
#phi = phi(SECRET_KEY.n)
print (SECRET_KEY.e)
#d = inverse_mod(e, phi)
#M = pow(C,d,SECRET_KEY.n)
r = ""
for k in data.split(","):
    #M = pow(int(k),Decimal  (1/SECRET_KEY.e))
    for i in range (33,126):
        result=pow(i,SECRET_KEY.e,SECRET_KEY.n)
        if (int(k)== result):
            r+=chr(i)
print(r)