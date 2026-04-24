a = input().upper()
alps = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"]
count_alp = []
max_alp = 0


for alp in alps:
    count_alp.append(a.count(alp))
max_alp = max((count_alp))


if count_alp.count(max_alp) > 1:
    print("?")
else:
    print(alps[count_alp.index(max_alp)])
