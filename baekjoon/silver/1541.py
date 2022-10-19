inp = input()
inp += ' '
arr = []

for i in range(len(inp)):
    if inp[i] == '-':
        arr.append(i)

result = 0
if arr:
    start = -1
    
    for j in range(len(arr)-1, -1, -1):
        plus_ix = []
        sum = 0
        sub = inp[arr[j]+1:start]
        for e in range(len(sub)):
            if sub[e] == '+':
                plus_ix.append(e)
        chk = 0
        if plus_ix:
            for k in range(len(plus_ix)):
                sum += int(sub[chk:plus_ix[k]])
                chk = plus_ix[k]
            sum += int(sub[chk:])
        else:
            sum += int(sub)
        result -= sum
        start = arr[j]
    
    result += int(inp[0:start])
else:
    result = eval(inp)
print(result)