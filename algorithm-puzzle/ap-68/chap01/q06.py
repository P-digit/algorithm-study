N = 2

nums = []

while N <= 10000:
    num = N*3 + 1
    chk = False
    while not chk:
        if num == 1:
            chk = True
        else:
            if num == N:
                nums.append(N)
                chk = True
            else:
                if num % 2 == 0:
                    num = num // 2
                else:
                    num = num * 3 + 1
    N += 2
print(len(nums))        

