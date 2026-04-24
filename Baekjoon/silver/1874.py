import sys


stk = []
n = int(sys.stdin.readline())
max_number = 0
result = ''
chk = 0

while chk != n:
    k = int(sys.stdin.readline())
    if result != 'NO':
        if k > max_number:
            for i in range(max_number+1, k+1):
                stk.append(i)
                result += '+'
            max_number = k
        if stk[-1] != k:
            result = 'NO'
        elif stk[-1] == k:
            result += '-'
            stk.pop()
    chk += 1

if result != "NO":
    for e in result:
        print(e)
else:
    print(result)
    
    
    
import sys



n = int(sys.stdin.readline())
arr = [int(sys.stdin.readline()) for _ in range(n)]

stk = []
max_number = 0
result = ''
chk = 0

while chk != n:

    if arr[chk] > max_number:
        for i in range(max_number+1, arr[chk]+1):
            stk.append(i)
            result += '+'
        max_number = arr[chk]
    if stk[-1] != arr[chk]:
        result = ''
        break
    elif stk[-1] == arr[chk]:
        result += '-'
        stk.pop()
    chk += 1

if result:
    for e in result:
        print(e)
else:
    print("NO")





    
    
    
