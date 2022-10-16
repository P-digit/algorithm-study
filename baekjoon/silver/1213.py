from itertools import permutations
in_str = input()

result = ''

dic = {}

for S in in_str:
    if S not in dic:
        dic[S] = 1
    else:
        dic[S] += 1

odd_count = 0
odd_str = ''

for k in dic:
    if dic[k] % 2:
        odd_count += 1
        odd_str = k


if len(in_str) % 2: # 문자열 길이가 홀수일 때
        if odd_count == 1:
            str_list = []
            for e in dic:
                if not dic[e] % 2:
                    str_list.append(e * (dic[e] // 2))
                else:
                    str_list.append(e * ((dic[e] - 1) // 2))
            str_list.sort()
            result = ''.join(str_list) + odd_str + ''.join(str_list[::-1])
            
            

else: # 문자열 길이가 짝수일 때
    if not odd_count:
        str_list = []
        for e in dic:
            str_list.append(e * (dic[e] // 2))
        str_list.sort()
        result = ''.join(str_list) + ''.join(str_list[::-1])
        
print(result if result else "I'm Sorry Hansoo")