#include <stdio.h>
#include <stdlib.h>

// N이 1000일 때 나올 수 있는 부분합의 최대 개수는 1000 * 1001 / 2 = 500,500개입니다.
// 넉넉하게 500,505로 전역 변수(BSS 영역)에 잡아주어 스택 오버플로우를 원천 차단합니다.
long long arr_a[1005];
long long arr_b[1005];
long long sum_a[500505];
long long sum_b[500505];

// qsort를 위한 오름차순 비교 함수 (바텀업 배치)
int CompareValues(const void *ptr1, const void *ptr2)
{
    long long value1 = *(long long *)ptr1;
    long long value2 = *(long long *)ptr2;

    if (value1 < value2)
    {
        return -1;
    }
    if (value1 > value2)
    {
        return 1;
    }
    return 0;
}

int main(void)
{
    long long target_value;
    if (scanf("%lld", &target_value) != 1)
        return 0;

    // 1. A 배열 입력 및 모든 부분합 구하기
    int size_a;
    scanf("%d", &size_a);
    for (int i = 0; i < size_a; i++)
    {
        scanf("%lld", &arr_a[i]);
    }

    int idx_a = 0;
    for (int i = 0; i < size_a; i++)
    {
        long long current_sum = 0;
        for (int j = i; j < size_a; j++)
        {
            current_sum += arr_a[j];
            sum_a[idx_a++] = current_sum;
        }
    }

    // 2. B 배열 입력 및 모든 부분합 구하기
    int size_b;
    scanf("%d", &size_b);
    for (int i = 0; i < size_b; i++)
    {
        scanf("%lld", &arr_b[i]);
    }

    int idx_b = 0;
    for (int i = 0; i < size_b; i++)
    {
        long long current_sum = 0;
        for (int j = i; j < size_b; j++)
        {
            current_sum += arr_b[j];
            sum_b[idx_b++] = current_sum;
        }
    }

    // 3. 만들어진 거대 부분합 배열 두 개를 오름차순으로 정렬
    qsort(sum_a, idx_a, sizeof(long long), CompareValues);
    qsort(sum_b, idx_b, sizeof(long long), CompareValues);

    // 4. 투 포인터(Two Pointers) 탐색 시작
    int left_ptr = 0;          // sum_a의 가장 작은 값(맨 앞)부터 출발
    int right_ptr = idx_b - 1; // sum_b의 가장 큰 값(맨 뒤)부터 출발

    // 정답이 21억 개를 가볍게 넘을 수 있으므로 반드시 long long으로 선언!!
    long long total_count = 0;

    while (left_ptr < idx_a && right_ptr >= 0)
    {
        long long current_sum = sum_a[left_ptr] + sum_b[right_ptr];

        if (current_sum == target_value)
        {
            // [핵심] 타겟을 찾았는데, 똑같은 숫자가 연속해서 여러 개 있을 수 있습니다!
            long long target_a = sum_a[left_ptr];
            long long target_b = sum_b[right_ptr];

            long long count_a = 0;
            long long count_b = 0;

            // sum_a 배열에서 target_a와 같은 숫자가 몇 개인지 센다
            while (left_ptr < idx_a && sum_a[left_ptr] == target_a)
            {
                count_a++;
                left_ptr++;
            }

            // sum_b 배열에서 target_b와 같은 숫자가 몇 개인지 센다
            while (right_ptr >= 0 && sum_b[right_ptr] == target_b)
            {
                count_b++;
                right_ptr--;
            }

            // 두 덩어리에서 나올 수 있는 조합의 수는 (A의 개수 * B의 개수)
            total_count += (count_a * count_b);
        }
        else if (current_sum < target_value)
        {
            left_ptr++; // 합이 모자라면 왼쪽 포인터를 올려서 값을 키움
        }
        else
        {
            right_ptr--; // 합이 넘치면 오른쪽 포인터를 내려서 값을 줄임
        }
    }

    // 5. 정답 출력
    printf("%lld\n", total_count);

    return 0;
}