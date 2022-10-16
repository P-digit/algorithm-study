queue = [None] * 10001

lo = -1
hi = -1

for _ in range(int(input())):
    order = input().split()

    if order[0] == "push":
        if lo == hi == -1:
            queue[10000] = int(order[-1])
            lo = 10000
            hi = 10000
        else:
            if queue[lo] >= int(order[-1]):
                queue[lo-1] = int(order[-1])
                lo -= 1
            else:
                ix = hi+1
                for i in range(lo, hi+1):
                    if queue[i] > int(order[-1]):
                        ix = i
                        break
                for j in range(hi,ix-1,-1):
                    queue[j+1] = queue[j]
                queue[ix] = int(order[-1])
                hi += 1

    if order[0] == "pop":
        if lo == hi == -1:
            print(-1)
        
        else:
            print(queue[lo])
            queue[lo] = None
            if lo == hi:
                lo = -1
                hi = -1
            else:
                lo += 1
    
    if order[0] == "size":
        print(0 if hi == lo == -1 else hi-lo+1)
    
    if order[0] == "empty":
        print(1 if hi == lo == -1 else 0)

    if order[0] == "front":
        print(queue[lo] if lo != -1 else -1)

    if order[0] == "back":
        print(queue[hi] if hi != -1 else -1)
