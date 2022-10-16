import sys

N, M = map(int, input().split())

dic = {}

for _ in range(N):
    adr, pwd = sys.stdin.readline().split()
    dic[adr] = pwd

for _ in range(M):
    sadr = sys.stdin.readline().strip()
    print(dic[sadr])
    