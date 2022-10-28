inp = input().strip()
arr = []

result = 0

for i in range(len(inp)):
    if inp[i] == '-':
        arr.append((i,"-"))
    elif inp[i] == "+":
        arr.append((i,"+"))
if not arr:
    result = int(inp)
else:
    result += int(inp[0:arr[0][0]])
    ix = arr[0][0]
    t = 1 if arr[0][1] == "+" else -1

    for e in range(1, len(arr)):
        result += (int(inp[ix+1:arr[e][0]]) * t)
        if arr[e][1] == "-":
            if t == 1:
                t = -1
        ix = arr[e][0]
    
    result += (int(inp[ix+1:]) * t)
print(result)
    