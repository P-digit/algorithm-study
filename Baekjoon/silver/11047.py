from copy import deepcopy


coin_number, money = map(int, input().split())
coins = [int(input()) for _ in range(coin_number)]

rest = deepcopy(money)
coin_count = 0



for i in range(len(coins)-1, -1, -1):
    if money // coins[i]:
        if rest == 0:
            break
        coin_count += (rest // coins[i])
        rest = rest % coins[i]
        
print(coin_count)

def sol():
    coins.reverse()
    ans = 0
    for coin in coins:
        ans += money // coin
        k %= coin
    print(ans)