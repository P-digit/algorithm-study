N = int(input())
arr = sorted([t for t in map(int, input().split())])
count = 0
for i in range(N):
    count += (arr[i] * (N-i))

print(count)

