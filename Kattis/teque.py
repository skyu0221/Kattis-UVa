from collections import deque
from sys import stdin, stdout

input = stdin.readline


def main():
    n = int(input())

    front = deque()
    back = deque()

    for _ in range(n):
        command, i = input().split()
        if command[-2] == 'c':
            back.append(i)
            if len(back) > len(front):
                front.append(back.popleft())
        elif command[-2] == 'n':
            front.appendleft(i)
            if len(back) + 1 < len(front):
                back.appendleft(front.pop())
        elif command[-2] == 'l':
            if len(front) == len(back):
                front.append(i)
            else:
                back.appendleft(i)
        else:
            i = int(i)
            if i < len(front):
                stdout.write(front[i] + '\n')
            else:
                stdout.write(back[i - len(front)] + '\n')


if __name__ == '__main__':
    main()
