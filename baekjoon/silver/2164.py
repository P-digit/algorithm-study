from collections import deque


def a():

    q = deque()

    for i in range(1, int(input()) + 1):
        q.append(i)


    while len(q) > 1:
        q.popleft()
        q.append(q[0])
        q.popleft()
        if len(q) == 1:
            break


    print(q[0])
        
def b():
    n = int(input())
    dq = deque(range(1, n + 1))
    while len(dq) > 1:
        dq.popleft()
        dq.append(dq.popleft())

    print(dq.popleft())

b()