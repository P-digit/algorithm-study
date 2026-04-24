import sys
from collections import deque


input = sys.stdin.readline


N,M,B = map(int, input().split())

board = []
result = {}

def is_valid_height(h):
    return 0 < h < 256

for _ in range(N):
    for e in map(int, input().split()):
        board.append(e)

h = 0

while h <= 256:
    time = 0
    reuse_block = 0
    need_block = 0
    for i in range(len(board)):
        if board[i] - h < 0:
            need_block += (h - board[i])
        else:
            reuse_block += (board[i] - h)

    if reuse_block + B < need_block:
        continue
    else:
        time = reuse_block * 2 + need_block

    if time in result:
        result[time].append(h-1)
    else:
        result[time] = [h-1]
    

print(min(result), max(result[min(result)]))


    
                
            
