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
    plus_ix = []
    for e in range(len(inp[:start])):
        if inp[:start][e] == '+':
            plus_ix.append(e)
    chk = 0
    if plus_ix:
        for k in range(len(plus_ix)):
            result += int(inp[:start][chk:plus_ix[k]])
            chk = plus_ix[k]
    else:
        result += int(inp[0:start])
else:
    plus_ix = []
    for e in range(len(inp)):
        if inp[e] == "+":
            plus_ix.append(e)
    if plus_ix:
        start = 0
        for m in plus_ix:
            result += int(inp[start:m])
            start = m
    else:
        result += int(inp)
print(result)