import sys

N, M = map(int, input().split())

n_h = set()
n_hs = []

for _ in range(N):
    n_h.add(sys.stdin.readline().strip('\n'))
for _ in range(M):
    name = sys.stdin.readline().strip('\n')
    if name in n_h:
        n_hs.append(name)


print(len(n_hs))
print(*sorted(n_hs), sep='\n')



