import heapq as hq
import sys

input = sys.stdin.readline


n = int(input())

arr = []


for _ in range(n):
    coord_x, coord_y = map(int, input().strip('\n').split())
    hq.heappush(arr, (coord_y, coord_x))

for _ in range(len(arr)):
    pop_y, pop_x = hq.heappop(arr)
    print(pop_x, pop_y)