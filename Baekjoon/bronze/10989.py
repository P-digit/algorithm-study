arr = [0] * 10001

for _ in range(int(input())):
    n = int(input())
    arr[n] += 1


for i in range(1, 10001):
    if arr[i]:
        for _ in range(arr[i]):
            print(i)