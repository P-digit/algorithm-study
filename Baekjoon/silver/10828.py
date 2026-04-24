import sys

input = sys.stdin.readline

stk = []
p = -1

for _ in range(int(input())):
    order = input().strip('\n').split()
    
    if order[0] == 'push':
        stk.append(order[-1])
        p += 1
    
    if order[0] == 'pop':
        if p < 0:
            print(-1)
        else:
            print(stk.pop(p))
            p += -1

    if order[0] == 'size':
        print(p+1 if p >= 0 else 0)

    if order[0] == 'empty':
        print(0 if p >= 0 else 1)

    if order[0] == 'top':
        print(stk[p] if p >= 0 else -1)