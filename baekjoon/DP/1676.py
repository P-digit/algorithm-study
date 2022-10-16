N = int(input())
count = 0

for i in range(N+1):
    if i % 5 == 0 and i != 0:
        t = i // 5
        count += 1
        while t:
            if t % 5 == 0:
                count += 1
                t = t // 5
            else:
                break
print(count)
