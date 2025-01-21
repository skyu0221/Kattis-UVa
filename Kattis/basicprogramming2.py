from collections import Counter
from sys import stdin, stdout

input = stdin.readline
n, t = map(int, input().split())

if t == 1:
    a = Counter(map(int, input().split()))
    for key in a:
        if a[7777 - key]:
            print("Yes")
            break
    else:
        print("No")
elif t == 2:
    a = Counter(map(int, input().split()))
    if a.most_common(1)[0][1] > 1:
        print("Contains duplicate")
    else:
        print("Unique")
elif t == 3:
    a = Counter(map(int, input().split()))
    v = a.most_common(1)[0]
    if v[1] > a.total() / 2:
        print(v[0])
    else:
        print(-1)
elif t == 4:
    a = sorted(map(int, input().split()))
    if len(a) % 2:
        print(a[len(a) // 2])
    else:
        print(a[len(a) // 2 - 1], a[len(a) // 2])
else:
    a = Counter(map(int, input().split()))
    s = ''
    for i in range(100, 1000):
        s += (str(i) + ' ') * a[i]
    stdout.write(s[:-1])