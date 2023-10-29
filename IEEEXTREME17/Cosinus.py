#10%
from math import gcd 
t = int(input())
for i in range(t):
    x = input()
    s = ""
    p = 1
    for j in range(len(x)):
        if (x[j] != '.'):
            s+= x[j]
        if (x[j] == '.'):
            nb = len(x)-j
            p = 10**(nb-1)
    
    s = int(s)
    g = gcd(p,s)
    k = p/g
    best = s
    ans = k
    
    for i in range(100):
       h = s*i
       if (abs(90-h%180) < abs(90-best%180)):
           best = h
           ans = i*k
    print(int(ans))
