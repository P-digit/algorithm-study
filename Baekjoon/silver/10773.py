import sys

input = sys.stdin.readline


stk = []

K = int(input())




for _ in range(K):
    N = int(input())

    if N == 0:
        stk.pop(-1)
    else:
        stk.append(N)


print(sum(stk))
