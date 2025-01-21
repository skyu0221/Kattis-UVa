alphabet = {'A': 0, 'B': 1, 'C': 2, 'D': 3, 'E': 4, 'F': 5, 'G': 6, 'H': 7}
reverse = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H']

cases = int(input())

for case in range(cases):

    x1, y1, x2, y2 = input().split()

    x1 = alphabet[x1]
    x2 = alphabet[x2]
    y1 = int(y1)
    y2 = int(y2)

    if (x1 + y1) % 2 != (x2 + y2) % 2:
        print("Impossible")
    elif x1 == x2 and y1 == y2:
        print("0", reverse[x1], y1)
    elif abs(x1 - x2) == abs(y1 - y2):
        print("1", reverse[x1], y1, reverse[x2], y2)
    elif 0 <= y1 - y2 + x1 + x2 and y1 - y2 + x1 + x2 <= 14 and \
            2 <= x1 - x2 + y1 + y2 and x1 - x2 + y1 + y2 <= 16:
        print("2", reverse[x1], y1,
              reverse[int((y1 - y2 + x1 + x2) / 2)],
              int((x1 - x2 + y1 + y2) / 2),
              reverse[x2], y2)
    else:
        print("2", reverse[x1], y1,
              reverse[int((y2 - y1 + x1 + x2) / 2)],
              int((x2 - x1 + y1 + y2) / 2),
              reverse[x2], y2)
