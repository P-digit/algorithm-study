N = int(input())

arr = [None] * (N+1)
rating = {}
M = 0


for i in range(N):
    x, y = map(int, input().split())
    arr[i+1] = (x, y, 0)

for e in range(1, N+1):
    MG = 0
    for l in range(1,N+1):
        if e != l:
            if arr[e][0] < arr[l][0] and arr[e][1] < arr[l][1]:
                MG += 1
    arr[e] = (arr[e][0], arr[e][1], MG)

for j in arr[1:]:
    print(j[-1]+1, sep=" ")

    
""" N = int(input())

arr = [None] * (N+1)
rating = {}
M = 0


for i in range(N):
    x, y = map(int, input().split())
    arr[i+1] = (x, y, 0)

for e in range(1, N):
    MG = 0
    for l in range(e+1,N+1):
        if arr[e][0] > arr[l][0] and arr[e][1] > arr[l][1]:
            MG += 1
    arr[e] = (arr[e][0], arr[e][1], MG)

    if MG > M :
        M = MG


ex_people = 0

for k in range(M,-1,-1):
    equal = []
    for l in range(1,N+1):
        if isinstance(arr[l], tuple):
            if arr[l][-1] == k:
                equal.append(l)
    if equal:
        for ix in equal:
            arr[ix] = 1 + ex_people
        ex_people += len(equal)
            
print(arr[1:])
 """

    
