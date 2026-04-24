import sys

input = sys.stdin.readline

deque = [None] * 20001
lp = 10000
rp = 10000

for _ in range(int(input())):
    order = input().split()
    if order[0] == "push_front":
        deque[lp] = order[-1]
        if lp == rp:
            rp += 1
        lp -= 1
    
    if order[0] == "push_back":
        deque[rp] = order[-1]
        if lp == rp:
            lp -= 1
        rp += 1

    if order[0] == "pop_front":
        if deque[lp+1] == None:
            print(-1)
        else:
            print(deque[lp+1])
            deque[lp+1] = None
            lp += 1

    if order[0] == "pop_back":
        if deque[rp-1] == None:
            print(-1)
        else:
            print(deque[rp-1])
            deque[rp-1] = None
            rp -= 1

    if order[0] == "size":
        print(0 if lp == rp else rp-lp-1)

    if order[0] == "empty":
        print(1 if rp == lp or rp - lp == 1 else 0)
    
    if order[0] == "front":
        print(deque[lp+1] if deque[lp+1] else -1)

    if order[0] == "back":
        print(deque[rp-1] if deque[rp-1] else -1)