import sys

N, M = map(int, sys.stdin.readline().split())

dic1 = {}
dic2 = {}
for i in range(1, N+1):
    pokemon = sys.stdin.readline().strip()
    dic1[str(i)] = pokemon
    dic2[pokemon] = i

for _ in range(M):
    q = sys.stdin.readline().strip()
    if q in dic1:
        print(dic1[q])
    else:
        print(dic2[q])

