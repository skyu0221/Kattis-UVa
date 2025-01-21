def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            return

        num = 9
        while n != 1:
            n = (n - 1) // num + 1
            num = 2 if num == 9 else 9

        if num == 2:
            print("Stan wins.")
        else:
            print("Ollie wins.")


if __name__ == '__main__':
    main()
