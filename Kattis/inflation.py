input()
ballons = list(map(int, input().split()))

ballons.sort()
minimum = 1
for i, num in enumerate(ballons, start=1):
    if num > i:
        print("impossible")
        break
    perc = num / i
    if perc < minimum:
        minimum = perc
else:
    print(minimum)
