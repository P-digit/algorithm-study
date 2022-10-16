from math import ceil

A, B, V = map(int, input().split())

M = ceil((V-A) / (A-B))
print(M+1)