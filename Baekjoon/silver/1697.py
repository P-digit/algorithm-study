from collections import deque

N, K = map(int, input().split())

def bfs():
    dq = deque()
    chked_num = set()
    dq.append((K, 0))
    while dq:
        start, count = dq.popleft()
        if start == N:
            return(count)
        nxt_num = [start-1, start+1]
        if not start % 2:
            nxt_num.append(start // 2)

        for e in nxt_num:
            if e not in chked_num:
                dq.append((e, count + 1))
                chked_num.add(e)

print(bfs())