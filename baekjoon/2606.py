from collections import deque

N = int(input())
arr = [[] for _ in range(N)]
chk = [False for _ in range(100)]

for _ in range(int(input())):
    a, b = map(int, input().split())
    if b not in arr[a-1]:
        arr[a-1].append(b)
    if a not in arr[b-1]:
        arr[b-1].append(a)
    

dq = deque()


for e in arr[0]:
    dq.append(e)

while dq:
    chk_num = dq.popleft()

    if len(arr[chk_num-1]):
        for e in arr[chk_num-1]:
            if not chk[e-1]:
                dq.append(e)

    if not chk[chk_num-1]:
        chk[chk_num-1] = True


chk[0] = False
print(sum(chk))
