def main():
    mapping = (
        '@', '8', '(', '|)', '3', '#', '6',
        '[-]', '|', '_|', '|<', '1', '[]\\/[]',
        '[]\\[]', '0', '|D', '(,)', '|Z', '$',
        "']['", '|_|', '\\/', '\\/\\/', '}{',
        '`/', '2'
    )
    plain = input().lower()
    encoded = str()
    for char in plain:
        if char.isalpha():
            encoded += mapping[ord(char) - ord('a')]
        else:
            encoded += char
    print(encoded)


if __name__ == '__main__':
    main()
