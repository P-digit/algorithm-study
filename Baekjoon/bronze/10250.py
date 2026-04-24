from math import ceil

for _ in range(int(input())):
    H, W, N = map(int,input().split())
    flo = H if N % H == 0 else N % H
    room = f'{ceil(N / H)}'if ceil(N / H) >= 10 else f'0{ceil(N / H)}'
    print(flo, end='')
    print(room)
