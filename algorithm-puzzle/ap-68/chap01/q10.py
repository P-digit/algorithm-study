european = [0, 32, 15, 19, 4, 21, 2, 25, 17, 34, 6, 27, \
            13, 36, 11, 30, 8, 23, 10, 5, 24, 16, 33, 1, \
            20, 14, 31, 9, 22, 18, 29, 7, 28, 12, 35, 3, 26]

american = [0, 28, 9, 26, 30, 11, 7, 20, 32, 17, 5, 22, \
            34, 15, 3, 24, 36, 13, 1, 0, 27, 10, 25, 29, \
            12, 8, 19, 31, 18, 6, 21, 33, 16, 4, 23, 35, 14, 2]

def sum_score(scores, n):
    result = 0
    for i in range(len(scores)):
        tmp = 0
        cnt = 0
        chk = i
        while cnt < n :
            if chk == len(scores):
                chk = 0
            tmp += scores[chk] 
            cnt += 1
            chk += 1
        if tmp >= result:
            result = tmp
    return result

def init():
    cnt = 0
    for i in range(2, 37):
        if sum_score(european, i) < sum_score(american, i):
            cnt += 1
    print(cnt)

init()