""" import sys
import random
input = sys.stdin.readline


n = int(input())
ml = list(map(int,input().split()))
ml.sort()
csm = int(input())
sml = sum(ml)

if sml <= csm:
    print(max(ml))
else:
    while True:
        max_m = ml[i]
        if max_m * (-i) + sum(ml[:i]) <= csm:
            break
        i -= 1
    a = csm - sum(ml[0:-3+1])
    if ml[i] * (-(i+1)) == a:
        print(max_m)
    else:
        lp = ml[i]
        rp = ml[i+1]
        while True:
            mm = (lp + rp) // 2
            if mm * -(i+1) > a:
                rp = mm
            elif mm * -(i+1) < a:
                lp = mm
            else:
                print(mm)
                break
            if lp + 1 == rp:
                print(lp)
                break

 """







def sol():
    n = int(input())
    req = list(map(int, input().split()))
    M = int(input())

    lo = 0
    hi = max(req)
    mid = (lo+hi) // 2
    ans = 0

    def is_possible(mid):
        return sum(min(r, mid) for r in req) <= M

    while lo <= hi:
        if is_possible(mid):
            lo = mid + 1
            ans = mid
        else:
            hi = mid - 1

        mid = (lo + hi) // 2

    print(ans)