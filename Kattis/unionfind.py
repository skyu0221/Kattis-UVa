from sys import stdin;input();p=list(range(5**9))
def f(x):
 x=int(x)
 if p[x]!=x:p[x]=f(p[x])
 return p[x]
for r in stdin:
 q,a,b=r.split()
 if q=='=':p[f(b)]=f(a)
 else:print(("no","yes")[f(a)==f(b)])