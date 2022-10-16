T = int(input())

arr = [(1, True), (1, False), (1, True), (2, False), (2, True)]
for i in range(5, 101):
    is_right = True if not i % 2 else False

    if is_right:
        arr.append((arr[-1][0]+arr[-5][0], False))
    else:
        arr.append((arr[-1][0]+arr[-5][0], True))

for _ in range(T):
    print(arr[int(input())-1][0])