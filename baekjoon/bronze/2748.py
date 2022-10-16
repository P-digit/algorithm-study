cashe = [-1] * 91
cashe[0] = 0
cashe[1] = 1


def f(n):
    if cashe[n] == -1:
        cashe[n] = f(n-1) + f(n-2)

    return cashe[n]
    
print(f(int(input()))) # top -down / down -top