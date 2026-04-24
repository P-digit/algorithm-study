a, b, c = map(int, input().split())

def get_rest(a, b, c):
    if b==1:
        return a%c
    elif b % 2:
        temp = get_rest(a, b//2, c)
        return a*(temp**2)%c
    else:
        temp = get_rest(a, b//2, c)
        return (temp**2)%c

print(get_rest(a, b, c))