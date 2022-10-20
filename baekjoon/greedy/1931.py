import sys
import heapq

N = int(input())

count = 0
hq = []

for i in range(N):
    start, end = map(int, sys.stdin.readline().split())
    heapq.heappush(hq, (end, start))

ex_start = -1
ex_end = -1

while hq:
    end, start = heapq.heappop(hq)
    if start >= ex_end:
        count+=1
        ex_start,ex_end = start, end

print(count)