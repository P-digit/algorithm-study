N = int(input())

count = N // 5
valid = False
cal = N % 5
while cal <= N:
    if cal % 3 == 0:
        valid = True
        count += cal // 3
        break
    
    cal += 5
    count -= 1

print(count if valid else -1)