from itertools import combinations as cb

N, M = map(int, input().split())

cases = cb(map(int,input().split()), 3)
result = M
result_case = []
for case in cases:
    s = M - sum(case)
    if s >= 0 and result > s:
        result = s
        result_case = list(case)
print(sum(result_case))
    