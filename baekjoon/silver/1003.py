N = int(input())



def fibonacci(n, dic):

    if n not in dic:
        dic[n] = (fibonacci(n-1, dic)[0]+fibonacci(n-2, dic)[0], fibonacci(n-1,dic)[1]+ fibonacci(n-2,dic)[1], fibonacci(n-1,dic)[2] + fibonacci(n-2,dic)[2])
    return dic[n]
    



for _ in range(N):
    dic = {0:(0, 1, 0), 1:(1, 0, 1)}
    n = int(input())
    fibonacci(n, dic)
    print(*dic[n][1:], sep=' ')
    
