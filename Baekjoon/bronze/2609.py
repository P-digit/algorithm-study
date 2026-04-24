a, b = map(int,input().split())
min = min(a, b)
max = max(a, b)
min_time = 1
now = max
while now > 1:
    if min % now == 0 and max % now == 0:
        min_time = now
        break
    now -= 1

print(min_time)
print((max // min_time) * (min // min_time) * min_time)
        

