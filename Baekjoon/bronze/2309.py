from itertools import combinations as cb


def mysubmit():

    sh = []

    for _ in range(9):
        sh.append(int(input()))
    sh.sort()

    for c in cb(sh, 7):
        sum = 0
        for n in c:
            sum += int(n)
        if sum == 100:
            for e in c:
                print(e)
            break

def sol():
    heights = [int(input()) for _ in range(9)]
    for combi in cb(heights, 7):
        if sum(combi) == 100:
            for height in sorted(combi):
                print(height)
            break

def sol_2():
    heights = [int(input()) for _ in range(9)]
    result = [e for e in heights]
    count = 0
    tot = sum(heights)
    for i in range(8):
        if count == 1:
            break
        for j in range(i+1,9):
            print(i, j)
            if tot - heights[i] - heights[j] == 100:
                for k in range(9):
                    if i != k and j != k:
                        print(sorted(heights)[k])
                count += 1    
                break

sol_2()

