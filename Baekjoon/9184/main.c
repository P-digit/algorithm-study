#include <stdio.h>

// 전역 변수 선언: 0~20까지 저장하므로 크기는 21. 모두 0으로 자동 초기화됨.
int dp[21][21][21];

// [메모이제이션 재귀 함수]
int CalculateW(int val_a, int val_b, int val_c)
{
    // 1. 기저 조건 (범위 이탈 시 Early Return)
    if (val_a <= 0 || val_b <= 0 || val_c <= 0)
    {
        return 1;
    }

    // 2. 20 초과 시 20으로 변환하여 다시 호출 (Early Return)
    if (val_a > 20 || val_b > 20 || val_c > 20)
    {
        return CalculateW(20, 20, 20);
    }

    // 3. 이미 계산된 값인지 확인 (0이 아니라면 과거의 기억을 바로 리턴)
    if (dp[val_a][val_b][val_c] != 0)
    {
        return dp[val_a][val_b][val_c];
    }

    // 4. 계산된 적이 없다면 재귀적으로 계산 후 배열에 '저장(Memoization)'
    if (val_a < val_b && val_b < val_c)
    {
        dp[val_a][val_b][val_c] = CalculateW(val_a, val_b, val_c - 1) + CalculateW(val_a, val_b - 1, val_c - 1) - CalculateW(val_a, val_b - 1, val_c);
    }
    else
    {
        dp[val_a][val_b][val_c] = CalculateW(val_a - 1, val_b, val_c) + CalculateW(val_a - 1, val_b - 1, val_c) + CalculateW(val_a - 1, val_b, val_c - 1) - CalculateW(val_a - 1, val_b - 1, val_c - 1);
    }

    // 5. 방금 갓 구워내어 저장한 따끈따끈한 값을 리턴
    return dp[val_a][val_b][val_c];
}

int main(void)
{
    int val_a, val_b, val_c;

    // 문제 조건: 무한 루프를 돌며 입력을 받다가 -1 -1 -1 이 들어오면 종료
    while (1)
    {
        if (scanf("%d %d %d", &val_a, &val_b, &val_c) != 3)
        {
            break;
        }

        // 종료 조건 검사 (Early Return 패턴의 응용인 Early Break)
        if (val_a == -1 && val_b == -1 && val_c == -1)
        {
            break;
        }

        // 로직 실행 및 출력 형식에 맞추어 출력
        int result = CalculateW(val_a, val_b, val_c);
        printf("w(%d, %d, %d) = %d\n", val_a, val_b, val_c, result);
    }

    return 0;
}