X = int(input())

dic = {1:0, 2:1, 3:1}

for i in range(4, (10**6)+1):
    temp = [dic[i-1] + 1]
    if i % 2 == 0:
        temp.append(dic[i//2] + 1)
    if i % 3 == 0:
        temp.append(dic[i//3] + 1)
    dic[i] = min(temp)
    
print(dic[X])

def dp(X):
    
    if X in dic:
        return dic[X]
    else:
        pass
    temp1 = dp(X-1) + 1
    
    if (X % 2) == 0:
        temp2 = dp(X//2) + 1
        temp1 = min(temp1, temp2)

    if (X % 3) == 0:
        temp2 = dp(X//3) + 1
        temp1 = min(temp1, temp2)

    return temp1
