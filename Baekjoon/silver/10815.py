import sys
from bisect import bisect_left as bl, bisect_right as br

input = sys.stdin.readline

def my_submit():


    N = int(input())
    N_card = sorted(list(map(int, input().split())))
    M = int(input())
    for M_card in list(map(int, input().split())):
        lo = 0
        hi = N - 1
        mid = (lo + hi) // 2
        result = False
        while lo <= hi:
            if N_card[mid] == M_card:
                result = True
                break
            if M_card > N_card[mid]:
                lo = mid + 1
            elif M_card < N_card[mid]:
                hi = mid - 1

            mid = (lo + hi) // 2
        
        if result:
            print(1, end=' ')
        else:
            print(0, end=' ')

    def sol_01():
        N = int(input())
        cards = sorted(map(int, input().split()))
        M = int(input())
        qry = list(map(int,input().split()))
        ans = []
        for q in qry:
            l = bl(cards, q)
            r = br(cards, q)
            ans.append(1 if r - l else 0)

        print(' '.join(map(str,ans))) # print(*ans)
                
    sol_01()