/* pseudo code
T_dp[N] : N일 때 가능한 이친수 저장 (마지막이 0, 1인 이친수 구분)

T_dp 초기값 저장
for(i=3->N까지) {
    T_dp[i] = (T_dp[i-1]의 0개수 + T_dp[i-1]의 1개수, T_dp[i-1]의 0개수);
}

T_dp[N] 출력

*/

#include <iostream>

using namespace std;

typedef pair<long long, long long> pinary;

static pinary T_dp[91] {};
static int N;

int main() {
    cin >> N;

    T_dp[1] = make_pair(0, 1);
    T_dp[2] = make_pair(1, 0);
    for(int i = 3; i <= N; ++i) {
        T_dp[i] = make_pair(T_dp[i-1].second + T_dp[i-1].first, T_dp[i-1].first);
    }
    cout << T_dp[N].first + T_dp[N].second;

    return 0;
}