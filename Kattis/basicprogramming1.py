n, t = map(int, input().split())
a = list(map(int, input().split()))

if t == 1:
    print(7)
elif t == 2:
    if a[0] > a[1]: print("Bigger")
    elif a[0] < a[1]: print("Smaller")
    else: print("Equal")
elif t == 3:
    print(sorted(a[:3])[1])
elif t == 4:
    print(sum(a))
elif t == 5:
    print(sum([i for i in a if (i + 1) % 2]))
elif t == 6:
    print(''.join([chr(97 + i % 26) for i in a]))
else:
    i = 0
    visited = set()
    while True:
        i = a[i]
        if i >= n: print("Out"); break
        elif i == n-1: print("Done"); break
        elif i in visited: print("Cyclic"); break
        else: visited.add(i)