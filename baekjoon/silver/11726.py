from math import factorial as fc

n = int(input())

count = 0
r = n
c = 0
while r >= 0:
    count += (fc(n-c) // (fc(c) * fc(r)))
    r -= 2
    c += 1
    

print(count % 10007)

def sol():
    MOD = 10_007

    dp = [0] * 1001
    dp[1] = 1
    dp[2] = 2
    n = int(input())
    for _ in range(3, 1001):
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD

    print(dp[n])

sol()