for i in range(1, 11):
    try:
        case = list(map(int, input()[2:].split()))
        print(f"Case {i}: {min(case)} {max(case)} {max(case) - min(case)}")
    except EOFError:
        break