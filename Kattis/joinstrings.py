i=input
t=[i() for _ in ' '*int(i())]
n={};e={};a=1
for _ in t[1:]:
 a,b=i().split();n[e.get(a,a)]=b;e[a]=e.get(b,b)
for _ in t:
 print(t[int(a)-1],end='');a=n.get(a,a)