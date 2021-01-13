cases = int(input())

for case in range(cases):
    k, n = map(int, input().split())
    s1 = n * (n + 1) // 2
    print(k, s1, s1 * 2 - n, s1 * 2)