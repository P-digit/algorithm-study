import sys
import heapq as hq

input = sys.stdin.readline


arr = []
n = int(input())

for i in range(n):
    olds, name = input().split()
    hq.heappush(arr, (int(olds), i, name))

for _ in range(n):
    olds, ac, name = hq.heappop(arr)
    print(olds, name)