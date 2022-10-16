MOD = 1_000_000_000

N = int(input())

cache = {}
for i in range(0, 10):
        cache[(i, 0)] = 1

def prove(h, m, cache):
    if m > 0:
        if (h, m) not in cache:
            if h == 0:
                cache[(h, m)] = prove(h+1, m-1, cache)
            elif h == 9:
                cache[(h, m)] = prove(h-1, m-1, cache)
            else:
                cache[(h, m)] = prove(h-1, m-1, cache) + prove(h+1, m-1, cache)

    return cache[(h, m)]


count = 0
for j in range(1, 10):
    count += prove(j, N-1, cache)

print(count % MOD)

def sol():
    MOD = 1_000_000_000
    cache = [[0] * 10 for _ in range(101)]
    for j in range(1, 10):
        cache[1][j] = 1

    for i in range(2, 101):
        for j in range(10):
            if j > 0:
                cache[i][j] += cache[i -1][j-1]
                cache[i][j] %= MOD

            if j < 9:
                cache[i][j] += cache[i-1][j+1]
                cache[i][j] %= MOD

    ans = 0
    N = int(input())
    for j in range(10):
        ans += cache[N][j]
        ans %= MOD
    print(ans)