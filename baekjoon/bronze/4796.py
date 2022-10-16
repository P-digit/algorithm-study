count = 1
while True:
    L, P, V = map(int, input().split())
    if L == P == V == 0:
        break

    H = V // P
    T = V % P

    if L >= T:
        A = T
    else:
        A = L

    print(f'Case {count}: {H * L + A}')
    count += 1