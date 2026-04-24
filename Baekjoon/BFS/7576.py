import sys
from collections import deque

M, N = map(int, input().split())
unripe_tmt = set()
no_tmt = set()
dq = deque()
count = 0

dx = (1, 0, -1, 0)
dy = (0, -1, 0, 1)

def is_valid(y,x):
    return 0 <= y < N and 0 <= x < M


for i in range(N):
    data = list(map(int, sys.stdin.readline().split()))
    for j in range(M):
        if data[j] == 0:
            unripe_tmt.add((i,j))
        elif data[j] == 1:
            dq.append((i,j,0))
        else:
            no_tmt.add((i, j))

while dq:
    chk_y, chk_x, days = dq.popleft()
    count = days if days > count else count
    for i in range(4):
        ny = chk_y + dy[i]
        nx = chk_x + dx[i]
        if is_valid(ny, nx) and (ny, nx) in unripe_tmt:
            dq.append((ny, nx, days+1))
            unripe_tmt.remove((ny, nx))

print(-1 if unripe_tmt else count)