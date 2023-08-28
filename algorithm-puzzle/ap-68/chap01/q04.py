from collections import deque
import sys


input = sys.stdin.readline

sticks = []

dq = deque(sticks)
count = 0
num = 1
N, M = map(int, input().split())
dq.append(N)

while dq:
    using = 0
    chk_stick = num
    while (using < M) and (num > using):
        length = dq.popleft()
        cut_length = int(length / 2)
        if (length % 2) == 1:
            if length == 3:
                dq.append(2)
            else:
                dq.append(cut_length)
                dq.append(cut_length + 1)
                chk_stick += 1
        else:
            if cut_length != 1:
                dq.append(cut_length)
                dq.append(cut_length)
                chk_stick += 1
            else:
                chk_stick -= 1
        using += 1
    count += 1
    num = chk_stick

print(count)
