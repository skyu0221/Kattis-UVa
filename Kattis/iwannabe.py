from heapq import nlargest
n, k = input().split()
k = int(k)

data = list()
for i in range(int(n)):
    data.append(tuple(map(int, input().split())))

sets = set()
for i in range(3):
    sets.update(nlargest(k, data, key=lambda x: x[i]))
print(len(sets))