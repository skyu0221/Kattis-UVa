def main():
    while True:
        m, n = input().split()
        if m == '0' and n == '0':
            return

        w = len(m) * 4 + 5
        r = '/'.join(list(str(int(m) * int(n))))
        r = list(' ' * ((len(m) + len(n)) * 2 - len(r)) + r)

        lattices_str = list()
        for a in n:
            for _ in range(2):
                lattices_str.append(str())
            for b in m:
                lattices = f"{int(a) * int(b):02d}"
                lattices_str[-2] += lattices[0]
                lattices_str[-1] += lattices[1]


        result = list()
        result.append('+' + '-' * (w - 2) + '+')
        result.append("|   " + "   ".join(list(m)) + "   |")
        for i in range(len(n)):
            result.append("| " + "+---" * len(m) + "+ |")
            result.append(f"|{r.pop(0)}|" + " /|".join(list(lattices_str.pop(0))) + " /| |")
            result.append("| " + "| / " * len(m) + '|' + n[i] + '|')
            result.append(f"|{r.pop(0)}|/ " + "|/ ".join(list(lattices_str.pop(0))) + "| |")
        result.append("| " + "+---" * len(m) + "+ |")
        result.append('|' + ' '.join(r) + "    |")
        result.append(result[0])

        print('\n'.join(result))


if __name__ == '__main__':
    main()
