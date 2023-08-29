from math import factorial

boy = 20
girl = 10

result = factorial(boy + girl) // (factorial(boy) * factorial(girl))
for i in range(girl, 0, -1):
    result -= (factorial(2*i) // pow(factorial(i), 2)) * (factorial(boy+girl-2*i) // (factorial(boy-i) * factorial(girl - i)))

print(result)