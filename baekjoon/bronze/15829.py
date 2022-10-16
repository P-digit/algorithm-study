from string import ascii_lowercase

n = int(input())
input_str = input()

alps = list(ascii_lowercase)
result = 0

for i in range(len(input_str)):
    ix = alps.index(input_str[i]) + 1
    result += ix * pow(31, i)

result = result % 1234567891

print(result)


