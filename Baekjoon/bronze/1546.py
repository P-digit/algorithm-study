""" n = int(input())
score_list = [int(e) for e in input().split()]
max_score = max(score_list)
for i in range(len(score_list)):
    score_list[i] = score_list[i]/max_score*100
print(sum(score_list)/n) """

n = int(input())
score_list = [int(e) for e in input().split()]
print(sum(score_list) * 100 / max(score_list) / n)