_ = input()
arr = set(map(int,input().split()))
M = input()
for e in list(map(int, input().split())):
    if e in arr:
        print(1)
    else:
        print(0)
