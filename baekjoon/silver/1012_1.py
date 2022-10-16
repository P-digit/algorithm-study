from collections import deque
from sys import stdin


T = int(stdin.readline())

def is_valid(y, x):
    return 0 <= y <= N-1 and 0 <= x <= M-1


dx = (1, 0, -1, 0, 0)
dy = (0, -1, 0, 1, 0)

for _ in range(T):
    M, N, K = map(int,stdin.readline().split())
    cabbage_coords = set()
    for _ in range(K):
        cabbage_x, cabbage_y = map(int, stdin.readline().split())
        cabbage_coords.add((cabbage_y, cabbage_x))
    board = [[0] * M for _ in range(N)] 
    for i in range(N):
        for j in range(M):
            coord_y = i
            coord_x = j
            cabbage_count = 0
            for k in range(5):
                ny = coord_y + dy[k]
                nx = coord_x + dx[k]
                if is_valid(ny, nx) and (ny, nx) in cabbage_coords:
                    cabbage_count += 1
            board[i][j] = cabbage_count
    use_worm = 0
    while len(cabbage_coords):
        print(board)
        cabbage_max = (0,0,0)
        for l in range(N):
            for m in range(M):
                if board[l][m] > cabbage_max[-1]:
                    cabbage_max = (l,m,board[l][m])
        max_cabbage = 1 if (cabbage_max[0], cabbage_max[1]) in cabbage_coords else 0
        use_worm += 1
        for o in range(4):
            cabbage_count = 0
            ny = cabbage_max[0] + dy[o]
            nx = cabbage_max[1] + dx[o]
            if is_valid(ny, nx) and board[ny][nx]:
                count = max_cabbage
                count += 1 if (ny, nx) in cabbage_coords else 0
                board[ny][nx] -= count
        for n in range(5):
            ny = cabbage_max[0] + dy[n]
            nx = cabbage_max[1] + dx[n]
            if is_valid(ny, nx) and (ny, nx) in cabbage_coords:
                cabbage_coords.remove((ny, nx))
        board[cabbage_max[0]][cabbage_max[1]] = 0
    print(use_worm)




        

        





            







            








