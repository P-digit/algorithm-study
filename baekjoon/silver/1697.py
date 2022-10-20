
from collections import deque

N, K = map(int, input().split())

def bfs():
    dq = deque()
    dq.append((N, 0))
    while dq:
        start, count = dq.popleft()
        if start == K:
            return(count)
        dq.append((start-1, count + 1))
        dq.append((start+1, count + 1))
        dq.append((start*2, count + 1))

print(bfs())