import bisect;import heapq as h;b=bisect.bisect_left;k=lambda x:x[0][0];q=[];l=len
for _ in' '*int(input()):
 c,e,g=(input()+' 0').split()[:3];e=-int(e);g=-int(g)
 if c[0]=='a':
  i=b(q,e,key=k)
  if i==l(q)or q[i][0][0]!=e:q.insert(i,[])
  h.heappush(q[i],(e,g))
 else:
  p=e;m=0
  while l(q)and p<=q[-1][0][0]:
   i=b(q,p,key=k)
   while l(q[i])and p<=q[i][0][0]:e,g=h.heappop(q[i]);m-=g;p-=e
   if l(q[i])==0:q.pop(i)
  print(m)