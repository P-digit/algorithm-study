_ = int(input())
arr = sorted([e for e in map(int, input().split())])
tgt = int(input())


if tgt in arr:
    print(0)
else:
    p = 0
    while p < len(arr):
        if tgt > arr[p]:
            p += 1
        else:
            break
    if p == 0:
        d = arr[p]-1
        if d == 1:
            print(0)
        else:
            ls = tgt -1
            rs = arr[p] - 1
            print((tgt - 1) * (arr[p]-tgt) + arr[p]-1-tgt)
    else:
        ls = tgt-arr[p-1]-1
        rs = arr[p]-tgt-1
        print(ls * (rs + 1) + rs)



    
        
