// 1. 입력 정적 할당 받기
// 2. 최대값, 총값 계산
// 3. 중간값으로 인출 후 M 초과 하는지 안 하는지 여부 파악
// 3-1. 임의의 값으로 몇 일 버티는지 구하는 함수
// 3-2. 해당 일수가 M보다 크면 인출값 크게, M보다 작으면 인출값 작게

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool CanSurvive(const int *expenses, const int total_days, const int limited_money, const int target_withdrawals)
{

    int withdraw_count = 1;
    int current_money = limited_money;

    for (int index = 0; index < total_days; index++)
    {
        if (current_money < expenses[index])
        {
            current_money = limited_money;
            withdraw_count++;
        }
        current_money -= expenses[index];
    }

    return withdraw_count <= target_withdrawals;
}

int GetMinMoney(int *expenses, int total_days, int min_predicted, int max_predicted, int target_withdrawals)
{

    int low = min_predicted;
    int high = max_predicted;
    int final_value = high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (CanSurvive(expenses, total_days, mid, target_withdrawals))
        {
            final_value = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return final_value;
}

int main(void)
{

    int total_days, withdraw_count;

    if (scanf("%d %d", &total_days, &withdraw_count) != 2)
        return 0;

    int *expenses = (int *)malloc(sizeof(int) * total_days);

    int max_expense = 0;
    long long sum_expenses = 0;

    for (int index = 0; index < total_days; index++)
    {

        scanf("%d", &expenses[index]);
        sum_expenses += expenses[index];

        if (expenses[index] > max_expense)
            max_expense = expenses[index];
    }

    int final_answer = GetMinMoney(expenses, total_days, max_expense, (int)sum_expenses, withdraw_count);
    printf("%d", final_answer);
    // printf("max_expense : %d, sum_expenses : %lld", max_expense, sum_expenses);
    free(expenses);
    return 0;
}