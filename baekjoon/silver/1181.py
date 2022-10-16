import heapq as hq
import sys

input = sys.stdin.readline


N = int(input())
heap = []
for _ in range(N):
    in_str = input().strip()
    if (len(in_str), in_str) in heap:
        pass
    else:
        hq.heappush(heap, (len(in_str), in_str))

for i in range(len(heap)):
    print(hq.heappop(heap)[-1])
