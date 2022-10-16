""" from copy import deepcopy
import sys


input = sys.stdin.readline

rs, cs = map(int, input().strip().split())

arr = [[]  for _ in range(rs)]

for r in range(rs):
    for e in list(input().strip()):
        arr[r].append([int(e), False])

arr[0][0][1] = True
min_tile = 0

dx = (1, 0, -1, 0)
dy = (0, -1, 0, 1)



def findroot(start_y, start_x, using, seed, min):

    if min:
        if using < min_tile[0]:
            inarr = deepcopy(seed)
            inarr[start_y][start_x][1] = True
        
            if start_y == rs -1 and start_x == cs -1:
                if min_tile[0] > using:
                    min_tile[0] = using
            else:
                for i in range(4):
                    ny = start_y + dy[i]
                    nx = start_x + dx[i]
                    if 0 <= ny < rs and 0 <= nx < cs and inarr[ny][nx][0] and not inarr[ny][nx][1]:
                        findroot(ny, nx, using+1, inarr, min_tile[0])
            
    else:
        inarr = deepcopy(seed)
        inarr[start_y][start_x][1] = True
    
        if start_y == rs -1 and start_x == cs -1:
            min = using
            
            

        for i in range(4):
            ny = start_y + dy[i]
            nx = start_x + dx[i]
            if 0 <= ny < rs and 0 <= nx < cs and inarr[ny][nx][0] and not inarr[ny][nx][1]:
                findroot(ny, nx, using+1, inarr, min_tile)

findroot(0,0,1,arr, min_tile)
print(min_tile) """

from collections import deque
import sys

input = sys.stdin.readline

rs, cs = map(int, input().strip().split())

board = [input().strip('\n') for _ in range(rs)]



dx = (1, 0, -1, 0)
dy = (0, -1, 0, 1)

def is_valid(y, x):
    return 0 <= y < rs and 0 <= x < cs



def bfs():
    chk = [[False] * cs  for _ in range(rs)] 
    chk[0][0] = True
    dq = deque()
    dq.append((0, 0, 1))
    while dq:
        y, x, d = dq.popleft()

        if y == rs-1 and x == cs-1:
            return d

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if is_valid(ny, nx) and board[ny][nx] == "1" and not chk[ny][nx]:
                chk[ny][nx] = True
                dq.append((ny, nx, d+1))


print(bfs())











