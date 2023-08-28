num = [0 for _ in range(100)]
k = 2
result = []
while k <= 100:
    for i in range(2, 101):
        if i >= k:
            if (i - k) % k == 0:
                num[i - 1] += 1
    k += 1

for j in range(len(num)):
    if num[j] % 2 == 0:
        result.append(j + 1)
print(*result, sep=" ")
