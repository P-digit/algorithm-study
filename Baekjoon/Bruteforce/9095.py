from math import factorial as ft
T = int(input())

for _ in range(T):
    n = int(input())
    valid_form = []
    result = 0
    for i in range((n//2) + 1):
        count_twe = i
        count_one = n - (2 * count_twe)
        count_three = 0
        while count_one >= 0:
            if (count_one + 2 * count_twe + 3 * count_three) == n:
                valid_form.append((count_one, count_twe, count_three))
            count_three += 1
            count_one -= 3
    for form in valid_form:
        result += ft(sum(form)) // (ft(form[0]) * ft(form[1]) * ft(form[2]))
    print(result)