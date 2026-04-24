// 1. dp 테이블 전역벽수로 설정 dy = ~y번째까지 물건, dx = 무게
// 2. 1~i번째까지의 물건을 고려한 가치 비교
// 3-1 무게 K에서 i번째 물건 선택 안 함
//--- ~i-1번째까지의 값
// 3-2 i번째 물건 선택함
//--- 해당 물건 가치 + ~i -1 가치 최대값을 3-1과 비교 후 큰 값 선정

int dp[105][100005];
int weights[105];
int values[105];

int GetMaxValue(int value1, int value2)
{
    if (value1 > value2)
        return value1;
    return value2;
}

int main(void)
{

    int total_stuffs;
    int target_weight;
    int final_answer;

    if (scanf("%d %d", &total_stuffs, &target_weight) != 2)
        return 0;

    for (int index = 1; index <= total_stuffs; index++)
    {
        scanf("%d %d", &weights[index], &values[index]);
    }

    for (int last_stuff = 1; last_stuff <= total_stuffs; last_stuff++)
    {
        for (int current_weight = 1; current_weight <= target_weight; current_weight++)
        {
            if (current_weight < weights[last_stuff])
                dp[last_stuff][current_weight] = dp[last_stuff - 1][current_weight];
            else
            {
                int take_item = values[last_stuff] + dp[last_stuff - 1][current_weight - weights[last_stuff]];

                int skip_item = dp[last_stuff - 1][current_weight];

                dp[last_stuff][current_weight] = GetMaxValue(take_item, skip_item);
            }
        }
    }

    final_answer = dp[total_stuffs][target_weight];
    printf("%d", final_answer);

    return 0;
}