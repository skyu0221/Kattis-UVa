def main():
    x = int(input())

    prime_numbers = list()
    counter = 0
    for i in range(2, int(x ** 0.5) + 1):
        for num in prime_numbers:
            if i % num == 0:
                break
        else:
            while x % i == 0:
                x //= i
                counter += 1
            prime_numbers.append(i)

    if x != 1:
        counter += 1
    print(counter)


if __name__ == '__main__':
    main()
