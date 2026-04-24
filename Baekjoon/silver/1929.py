from bisect import bisect_left as bl, bisect_right as br
import time



min, max = map(int, input().split())
start = time.time()

prime_list = []
prime_list.append(2)

chk_prime = 0

for i in range(1, max+1):
    if i == 1:
        continue
    if not prime_list[chk_prime] ** 2 > i:
        chk_prime += 1
    valid = True
    ix = 0
    while ix <= chk_prime:
        if not i % prime_list[ix]:
            valid = False
            break
        ix += 1
    if valid:
        prime_list.append(i)

min_l = bl(prime_list, min)

print(*prime_list[min_l:], sep = "\n")

""" def prime_list(a,n):
    n1 = n+1
    list1 = [True] * n1
    m = int(n1 ** 0.5)
    for i in range(2, m + 1):
        if list1[i] == True:          
            for j in range(i+i, n1, i): 
                list1[j] = False

    return [i for i in range(a, n1) if list1[i] == True and i > 1]

a,n = map(int,input().split())
c = prime_list(a,n)
for i in c:
    print(i) """







""" min, max = map(int, input().split())

board = []

def is_valid(prime, number):
    return not number % prime


for i in range(min, max+1):
    ix = 0
    while i <= max:
        if board[ix] ** 2 > i:
            valid = True
            for p in board:
                if not is_valid:
                    valid = False
                    break
            if valid:
                board.append(i)
        else:


 """
