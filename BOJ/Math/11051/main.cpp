#include <iostream>

using namespace std;

int T_dp[1005][1005] {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;

    for(int i = 1; i<1000; ++i) {
        T_dp[i][i] = 1;
        T_dp[i][1] = i;
        T_dp[i][0] = 1;
    }

    for(int i = 2; i<=1000; ++i) {
        for(int j = 1; j<i; ++j) {
            T_dp[i][j] = T_dp[i-1][j-1] + T_dp[i-1][j];
            T_dp[i][j] = T_dp[i][j] % 10007;
        }
    }

    cout << T_dp[N][K];

    return 0;
}