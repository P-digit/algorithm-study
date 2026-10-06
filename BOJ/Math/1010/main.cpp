#include <iostream>

using namespace std;

static long long T_dp[31][31] {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i = 1; i<=30; ++i) {
        T_dp[0][i] = 1;
        T_dp[i][i] = 1;
        T_dp[1][i] = i;
    }

    for(int i = 2; i<=30; ++i) {
        for(int j = 1; j<i; ++j) {
            T_dp[j][i] = T_dp[j-1][i-1] + T_dp[j][i-1];
        }
    }

    int Q;
    cin >> Q;
    for(int i = 0; i<Q; ++i) {
        int N, M;
        cin >> N >> M;
        cout << T_dp[N][M] << '\n';
    }

    return 0;

}
