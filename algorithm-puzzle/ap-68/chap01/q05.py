import sys

input = sys.stdin.readline

count = 0


money, max = map(int, input().split())
M = int(input())
units = [0 for _ in range(M)]


for i in range(M):
    units[i] = int(input())

units.sort()

for j in range(int(money / units[-1]) + 1 if money / units[-1] < max else max + 1):
    last = money - units[-1] * j
    for k in range(int(last / units[-2]) + 1 if last / units[-2] < max else max + 1):
        last1 = last - units[-2] * k
        for l in range(
            int(last1 / units[-3]) + 1 if last1 / units[-3] < max else max + 1
        ):
            last2 = last1 - units[-3] * l
            for m in range(
                int(last2 / units[-4]) + 1 if last2 / units[-4] < max else max + 1
            ):
                result = last2 - units[-4] * m
                if result == 0 and (j + k + l + m) <= 15:
                    count += 1
                    print(f"500: {j}, 100: {k}, 50: {l}, 10: {m}")
print(count)
