de_list = set()
de_list.add(2)
n = 3
while n < 1001:
    is_de = True
    for de in de_list:
        if not n % de:
            is_de = False
            break
    if is_de == True:
        de_list.add(n)
    n += 1

N = int(input())
count = 0
for m in map(int, input().split()):
    if m in de_list:
        count += 1

print(count)