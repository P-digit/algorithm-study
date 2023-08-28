import re

N = 1000
operator = ['', '+', '*', '-']
expression = ''
result = []

while (N<10000):
    str_N = str(N)
    for i in range(4):
        for j in range(4):
            for k in range(4):
                if ((i+j+k) > 0 ):
                    expression = str_N[0] + operator[i] + str_N[1] + operator[j] + str_N[2] + operator[k] + str_N[3]
                    expression = re.sub(r"00(\d+)", r"\1", expression)
                    expression = re.sub(r"0(\d+)", r"\1", expression)
                    if (str(N) == str(eval(expression))[::-1]):
                        result.append(N)
    N+=1
print(result)