import sys

input = sys.stdin.readline

N, P = map(int, input().split())

dic = {}

count = 0

for _ in range(N):
    l, t = map(int, input().split())
    if l not in dic:
        dic[l] = [t]
        count += 1
    else:
        if dic[l][-1] < t:
            dic[l].append(t)
            count += 1
        else:
            while True:
                if len(dic[l]):
                    if dic[l][-1] > t:
                        dic[l].pop(-1)
                        count += 1
                    else:
                        break
                else:
                    break

            if len(dic[l]):
                if dic[l][-1] != t:
                    dic[l].append(t)
                    count += 1
            else:
                dic[l].append(t)
                count += 1
print(count)

def sol():
    input = sys.stdin.readline
    N, P = map(int, input().split())
    stk = [[] for _ in range(7)]
    ans = 0
    for _ in range(N):
        line, p = map(int, input().split())
        while stk[line] and stk[line][-1] > p:
            stk[line].pop()
            ans += 1

        if stk[line] and stk[line][-1] = p:
            continue
