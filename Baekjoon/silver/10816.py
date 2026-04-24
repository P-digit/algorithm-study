import sys

input = sys.stdin.readline


dic = {}

N = int(input())

for e in map(int, input().split()):
    if e in dic:
        dic[e] += 1
    else:
        dic[e] = 1
M = int(input())

for c in map(int, input().split()):
    print(dic[c] if c in dic else 0)
