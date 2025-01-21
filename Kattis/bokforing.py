def main():
    n, q = map(int, input().split())
    n += 1

    wealth = [0] * n
    last_modify = [0] * n
    for row in range(q):
        command = input()
        if command[0] == 'S':
            _, i, v = command.split(' ')
            wealth[int(i)] = int(v)
            last_modify[int(i)] = row

        elif command[0] == 'R':
            _, v = command.split(' ')
            wealth[0] = int(v)
            last_modify[0] = row + 1

        else:
            _, i = command.split(' ')
            if last_modify[int(i)] < last_modify[0]:
                print(wealth[0])
            else:
                print(wealth[int(i)])


if __name__ == '__main__':
    main()