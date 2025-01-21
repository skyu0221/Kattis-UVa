import sys
for l in sys.stdin:
 k=int(l);r=""
 while k:r+="0125986"[k%7];k//=7
 print(r)