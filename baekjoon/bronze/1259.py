while True:
    in_int = input()
    if in_int == '0':
        break

    reverse_int = in_int[::-1] if in_int[-1] != "0" else in_int[::-1].lstrip("0")

    if reverse_int == in_int:
        print("yes")
    else:
        print("no")
    