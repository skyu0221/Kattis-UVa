def main():
    t = int(input())
    for _ in range(t):
        s = int(input())
        tree = dict()

        for _ in range(s):
            args = input().split()
            if len(args) == 2:
                tree[args[0]] = 0 if args[1][0] == 'c' else 1
            else:
                tree[args[0]] = args[1:]

        print(calculate_sum(tree, '1'))


def calculate_sum(tree, node):
    if isinstance(tree[node], int):
        return tree[node]
    value = 0
    for child in tree[node]:
        value += calculate_sum(tree, child)
    tree[node] = value
    return value


if __name__ == '__main__':
    main()
