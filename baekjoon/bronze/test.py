from math import ceil

N = int(input())
pay_Y = 0
pay_M = 0
for e in map(int, input().split()):
    pay_Y += int(ceil((e+1)/30)) * 10
    pay_M += int(ceil((e+1)/60)) * 15
if pay_Y == pay_M:
    print("Y "+ "M "+ str(pay_Y))
else:
    print("Y " + str(pay_Y)if pay_M > pay_Y else "M " + str(pay_M))
    