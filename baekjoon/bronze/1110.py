N = int(input())

test = str(N) if N > 9 else '0'+str(N)

count = 0
while True:
    test = test[-1] + str(int(test[0]) + int(test[1]))[-1]
    print(test)
    count += 1
    if int(test) == N:
        break
    if int(test) < 10:
        test = '0' + test


print(count)