import sys
import heapq as hq


input = sys.stdin.readline

N = int(input())

sum = 0
arr = [None] * N
dic = {}
nmax = -4000
nmin = 4000

for i in range(N):
    n = int(input())
    arr[i] = n
    sum += n
    if n in dic:
        dic[n] += 1
    else:
        dic[n] = 1

    if nmax < n:
        nmax = n
    if nmin > n:
        nmin = n
    
arr.sort()
mode = max(dic.values())
mode_list = []

for k, v in dic.items():
    if v == mode:
        hq.heappush(mode_list, k)
if len(mode_list) > 1:
    hq.heappop(mode_list)
    mode = hq.heappop(mode_list)
else:
    mode = hq.heappop(mode_list)

print(round(sum / N))
print(arr[N // 2])
print(mode)
print((nmax)-(nmin))

