#100%
import re
N=int(input())
for i in range(N):
    k=int(input())
    S=input()
    is_plain=re.search(R"\bthe\b",S)
    L=[]
    for s in S:
        if not s.isalpha():
            L.append(s)
            continue
        if is_plain:
            L.append(chr((ord(s)-ord('a')-k)%26+ord('a')))
        else:
            L.append(chr((ord(s)-ord('a')+k)%26+ord('a')))
    print("".join(L))
