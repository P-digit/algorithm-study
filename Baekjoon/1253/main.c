#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int CompareValues(const void *ptr1, const void *ptr2)
{
    long long value1 = *(long long *)ptr1;
    long long value2 = *(long long *)ptr2;

    if (value1 < value2)
        return -1;
    if (value1 > value2)
        return 1;
    return 0;
}

bool IsGoodValue(long long *numbers, int total_numbers, int target_idx)
{
    long long target_value = numbers[target_idx];
    int left_ptr = 0;
    int right_ptr = total_numbers - 1;

    while (left_ptr < right_ptr)
    {
        if (left_ptr == target_idx)
        {
            left_ptr++;
            continue;
        }

        if (right_ptr == target_idx)
        {
            right_ptr--;
            continue;
        }

        long long sum_value = numbers[left_ptr] + numbers[right_ptr];

        if (sum_value == numbers[target_idx])
            return true;
        else if (sum_value < target_value)
            left_ptr++;
        else
            right_ptr--;
    }

    return false;
}
int CountTotalGoodVal(long long *numbers, int total_numbers)
{
    int total_count = 0;
    for (int index = 0; index < total_numbers; index++)
    {
        if (IsGoodValue(numbers, total_numbers, index))
            total_count++;
    }

    return total_count;
}

int main(void)
{
    int total_numbers;
    int final_result;

    if (scanf("%d", &total_numbers) != 1)
        return 0;

    long long *numbers = (long long *)malloc(sizeof(long long) * total_numbers);
    for (int index = 0; index < total_numbers; index++)
    {
        scanf("%lld", &numbers[index]);
    }

    qsort(numbers, total_numbers, sizeof(long long), CompareValues);

    final_result = CountTotalGoodVal(numbers, total_numbers);

    printf("%d", final_result);
    free(numbers);

    return 0;
}
