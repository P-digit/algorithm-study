from collections import deque

N, M  =  map(int, input().split())

users = {}
result = {}


for _ in range(M):
    A, B = map(int, input().split())
    for _ in range(2):
        if A in users:
            users[A].append(B)
        else:
            users[A] = [B]
        A, B = B, A

for i in range(1, N+1):
    dq = deque()
    chk_board = [False] * 101
    for j in users[i]:
        l, h = min(i,j), max(i,j)
        if (l, h) not in result:
            result[(l, h)] = 1
        chk_board[j] = True
        dq.append((i, j, 1))
    while dq:
        user, chk_number, count = dq.popleft()
        chk_board[chk_number] = True
        count += 1
        for element in users[chk_number]:
            if element != user:
                l, h = min(user, element), max(user, element)
                if not chk_board[element]:
                    if (l, h) not in result:
                        result[(l,h)] = count
                    dq.append((user, element, count))

ans = (6*99, 100)

for m in range(1, N+1):
    sum = 0
    for k,v in result.items():
        if m in k:
            sum += v
    if (sum, m) < ans:
        ans = (sum, m)

print(ans[1])
        





        
        

