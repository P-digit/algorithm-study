import time
start = time.time()

arr = set()
i = 0
while True:
    if '666' in str(i):
        arr.add(i)
    i += 1

    if len(arr) == 10000:
        break

arr = sorted(list(arr))
print(arr[int(input())-1])