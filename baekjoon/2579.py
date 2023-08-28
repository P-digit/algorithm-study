import sys

input = sys.stdin.readline

N = int(input())
scores = [0 for _ in range(N)]

for i in range(N):
    scores[i] = int(input())

one = 0
two = 0
start = N - 1
result = 0


end = 0

for j in range(N/2)