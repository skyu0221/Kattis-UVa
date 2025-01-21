def main():
    encoding = (
        "xxxxxxx"
        "x.....x"
        "x.....x"
        "x.....x"
        "xxxxxxx",
        "......."
        "......."
        "......."
        "......."
        "xxxxxxx",
        "xxxx..x"
        "x..x..x"
        "x..x..x"
        "x..x..x"
        "x..xxxx",
        "x..x..x"
        "x..x..x"
        "x..x..x"
        "x..x..x"
        "xxxxxxx",
        "...xxxx"
        "...x..."
        "...x..."
        "...x..."
        "xxxxxxx",
        "x..xxxx"
        "x..x..x"
        "x..x..x"
        "x..x..x"
        "xxxx..x",
        "xxxxxxx"
        "x..x..x"
        "x..x..x"
        "x..x..x"
        "xxxx..x",
        "......x"
        "......x"
        "......x"
        "......x"
        "xxxxxxx",
        "xxxxxxx"
        "x..x..x"
        "x..x..x"
        "x..x..x"
        "xxxxxxx",
        "x..xxxx"
        "x..x..x"
        "x..x..x"
        "x..x..x"
        "xxxxxxx"
    )

    decoding = {
        "xxx.xx": '0',
        "..x..x": '1',
        "x.xxx.": '2',
        "x.xx.x": '3',
        ".xxx.x": '4',
        "xx.x.x": '5',
        "xx.xxx": '6',
        "x.x..x": '7',
        "xxxxxx": '8',
        "xxxx.x": '9',
        "...x..": '+'
    }

    encoded_text = str()
    for _ in range(2):
        encoded_text += input()[2::6]
        text = input()
        encoded_text += text[0::6]
        encoded_text += text[4::6]
        input()
    input()

    num_char = len(encoded_text) // 6

    decoded_text = str()
    for i in range(num_char):
        decoded_text += decoding[encoded_text[i::num_char]]

    result = str(eval(decoded_text))
    encoded_text = str()
    for char in result:
        encoded_text += encoding[int(char)]
        encoded_text += "......."
    encoded_text = encoded_text[:-7]
    for i in range(6, -1, -1):
        print(encoded_text[i::7])


if __name__ == '__main__':
    main()
