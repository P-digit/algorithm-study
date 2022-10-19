import sys

N = int(input())

arr = []

for i in range(N):
    start, end = map(int, sys.stdin.readline().split())
    arr.append((end, start))
arr.sort()
chk_ix = 0
count = 1
while True:
    if chk_ix == len(arr)-1:
        break
    for e in range(chk_ix+1,len(arr)):
        if arr[chk_ix][0] <= arr[e][1]:
            chk_ix = e
            count += 1
            break
print(count)







