from collections import deque
import heapq
from sys import stdin




def sol():
    T = int(stdin.readline())

    dx = (1, 0, -1, 0)
    dy = (0, -1, 0, 1)
    result = [[0] for _ in range(T)]

    for j in range(T):
        dq = deque()
        cabbage_set = set()
        hq = []
        used_set = set()
        _, _, K = map(int, stdin.readline().split())
        for _ in range(K):
            x, y = map(int, stdin.readline().split())
            cabbage_set.add((y, x))
            heapq.heappush(hq, (y, x))
        count = 0
        while hq:
            chk_y, chk_x = heapq.heappop(hq)
            if (chk_y, chk_x) not in used_set:
                dq.append((chk_y, chk_x))
                count += 1
                used_set.add((chk_y, chk_x))
                while dq:
                    y, x = dq.popleft()
                    for i in range(4):
                        ny = y + dy[i]
                        nx = x + dx[i]
                        if (ny, nx) in cabbage_set and (ny, nx) not in used_set:
                            dq.append((ny, nx))
                            used_set.add((ny, nx))
        result[j] = count
    print(*result, sep='\n')
sol()


""" result = [].

for _ in range(T):
    M, N, K = map(int,stdin.readline().split())
    cabbage_set = set()

    for _ in range(K):
        cabbage_x, cabbage_y = map(int, stdin.readline().split())
        cabbage_set.add((cabbage_y, cabbage_x))
    chked_coord = set()
    count = 0
    for i in range(N):
        x = 0
        while x < M:
            if (i, x) in cabbage_set and (i, x) not in chked_coord:
                count += 1
                dq.append((i, x))
                while dq:
                    chk_y, chk_x = dq.popleft()
                    chked_coord.add((chk_y, chk_x))
                    for j in range(4):
                        ny = chk_y + dy[j]
                        nx = chk_x + dx[j]
                        if is_valid(ny, nx) and (ny, nx) in cabbage_set and (ny, nx) not in chked_coord:
                            dq.append((ny, nx))
            x+=1
    result.append(count)
print(*result, sep='\n')

 """
""" for _ in range(T):
    M, N, K = map(int,stdin.readline().split())
    board = [[0]*M for _ in range(N)]
    for _ in range(K):
        cabbage_x, cabbage_y = map(int, stdin.readline().split())
        board[cabbage_y][cabbage_x] = 1
    chk = [[False] * M for _ in range(N)]
    count = 0
    for i in range(N):
        for j in range(M):
            if board[i][j] and chk[i][j] != True:
                dq = deque()
                count += 1
                dq.append((i,j))
                while dq:
                    y, x = dq.popleft()
                    chk[y][x] = True
                    for k in range(4):
                        ny = y + dy[k]
                        nx = x + dx[k]
                        if is_valid(ny,nx):
                            if board[ny][nx] == 1 and chk[ny][nx] == False:
                                dq.append((ny,nx))
    result.append(count)
    del chk
    del board
print(*result, sep='\n') """