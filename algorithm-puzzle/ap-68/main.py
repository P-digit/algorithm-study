s = int(input())
g = [None] * s
i = 0 + 1
k = 0
t = 0
for e in input().split(' '):
    g[k] = int(e)
    k+=1
n = int(input())
if n in g:
    t = 0
else:
    g.sort()
    if g[0] > n:
        t = ((n - 1)*(g[0]-1 - n + 1) + (g[0]-1 - n))
    else:
        while True:
            if g[i] > n:
                break
            i += 1 
        min = g[i-1] + 1
        max = g[i] - 1
        if min == max:
            t = 0
        else:
            t = ((n - min) * (max - n + 1)) + (max - n)
print(t)

aaa
bbbb
ccccc