try:
 while 1:
  n,m=map(int,(input()).split())
  s=[{i} for i in range(n+1)]
  for _ in ' '*m:
   a,b,c=list(map(int,(input()+' 0').split()))[:3]
   if b in s[c]:continue
   if a==1:
    if len(s[b])<len(s[c]):b,c=c,b
    s[b].update(s[c])
    for i in s[c]:s[i]=s[b]
   elif a==2:s[b].remove(b);s[c].add(b);s[b]=s[c]
   else: print(len(s[b]),sum(s[b]))
except: pass