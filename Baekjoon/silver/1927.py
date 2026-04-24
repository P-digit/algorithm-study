import heapq
import sys
N = int(input())


hq = []
for _ in range(N):
    ord = int(sys.stdin.readline())
    if ord == 0:
        if hq:
            print(heapq.heappop(hq))
        else:
            print(0)
    else:
        heapq.heappush(hq, ord)