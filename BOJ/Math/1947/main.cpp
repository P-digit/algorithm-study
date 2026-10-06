#include <iostream>

using namespace std;

long long T_dp[1000001] {};
int mod = 1000000000;

int main() {
    int N;
    cin >> N;

    T_dp[1] = 0;
    T_dp[2] = 1;
    for(int i = 3; i <=N; ++i) {
        T_dp[i] = (i-1) * (T_dp[i-2] + T_dp[i-1]);
        T_dp[i] %= mod;
    }

    cout << T_dp[N];

    return 0;

}
