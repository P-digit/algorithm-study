n, e = map(int, input().split())
nl = {}
count = 0

for nn in range(1, n+1):
    nl[nn] = []
    
for _ in range(e):
    f, l = map(int, input().split())
    nl[f].append(l)
    nl[l].append(f)

chk = [False] * n

def dfs(now):
    chk[now-1] = True
    for e in nl[now]:
        if not chk[e-1]:
            dfs(e)

for i in range(n):
    if not chk[i]:
        dfs(i+1)
        count += 1

print(count)
