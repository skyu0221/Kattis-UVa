import random as r
p = 0
while p != 99:
    if p % 3 != 0:
        p += 3 - p % 3
    else:
        p += r.randint(1, 2)
    print(p)
    if p == 99:
        exit()
    p = int(input())
