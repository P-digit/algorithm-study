import sys

N, M = map(int, input().split())
base = list(map(int, sys.stdin.readline().split()))

arr = [0 for _ in range(N)]
result = 0

for i in range(N):
    arr[i] = arr[i-1] + base[i] if i != 0 else base[i]

for _ in range(M):

    a, b = map(int, input().split())
    if a != b:
        if a == 1:
            result = arr[b-1]
        else:
            result = arr[b-1] - arr[a-2]

    else:
        result = base[a-1]

    print(result)

