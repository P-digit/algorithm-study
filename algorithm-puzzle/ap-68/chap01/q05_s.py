from collections import deque

cnt = 0


def change(target, coins, usable):
    global cnt
    coin = coins.popleft()
    if len(coins) == 0:
        if target // coin <= usable:
            cnt += 1
    else:
        for i in range(0, target // coin + 1):
            change(target - coin * i, coins.copy(), usable - i)


def init():
    money, max = map(int, input().split())
    num = int(input())
    units = [0 for _ in range(num)]
    for i in range(num):
        units[i] = int(input())
    change(money, deque(units), max)
    print(cnt)


init()
