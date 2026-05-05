/* pseudo code
1. T_dp[i]의 최대값은 max(i일때의 상담을 할 때, 안 할 때) 범위를 넘어가면 수입 x -> 0 처리

int T_dp[30];
int T_period[30];
int T_earn[30];


for(i->N까지) {
    T_dp[i] = max(당일 상담 일정이 끝나는 날의 최대값 + 그 다음 상담 가능 날, 당일 상담을 하지 않고 다음 날의 최대값);
} // 일정 후반부의 최대값 설정 필요


*/

#include <iostream>

using namespace std;

int getMaxMoney(int today);

static int T_dp[30] {};
static int T_period[30];
static int T_earn[30] {};

static int N;


int main() {
    cin >> N;

    fill(&T_dp[0], &T_dp[30], -1);
    for(int i = 1; i<=N; ++i) {
        cin >> T_period[i] >> T_earn[i];
    }
    
    cout << getMaxMoney(1);

    return 0;
}

int getMaxMoney(int today) {
    if(today > N) {
        return 0;
    }
    if(T_dp[today] != -1) {
        return T_dp[today];
    }
    else {
        int end_work = today + T_period[today] - 1;
        if(end_work > N) {
            if(today == N) {
                return T_dp[today] = 0;
            }
            else {
                return T_dp[today] = getMaxMoney(today + 1);
            }
        }
        else {
            return T_dp[today] = max(T_earn[today] + getMaxMoney(end_work + 1), getMaxMoney(today + 1));
        }
    }
}