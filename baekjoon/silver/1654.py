from math import ceil
import sys

input = sys.stdin.readline

K, N = map(int, input().strip("\n").split())

arr = [int(input()) for _ in range(K)]

lv = 1
rv = 2**31 - 1


while lv != rv:
    lan_cable = 0
    cut = ceil((lv + rv) / 2)
    if cut == lv or cut == rv:
        break
    for e in arr:
        lan_cable += (e // cut)
    if lan_cable >= N:
        lv = cut
    else:
        rv = cut

value = [lv, rv]

if rv == lv:
    print(lv)
else:
    for i in range(2):
        lan_cable = 0
        for e in arr:
            lan_cable += e // value[i]
        if lan_cable == N:
            value[i] = (value[i], True)
        else:
            value[i] = (value[i], False)
    print(value[-1][0] if value[-1][-1] else value[0][0])
