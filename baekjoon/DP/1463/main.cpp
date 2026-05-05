#include <iostream>

static int T_dp [1000001] {};

using namespace std;

int main() {
    int N;
    cin >> N;
    T_dp[2] = 1;
    T_dp[3] = 1;
    for(int i = 4; i <= 1000000; ++i) {
        T_dp[i] = T_dp[i-1] + 1;
        if(i % 2 == 0) T_dp[i] = min(T_dp[i], T_dp[i/2]+1);
        if(i % 3 == 0) T_dp[i] = min(T_dp[i], T_dp[i/3]+1);
    }

        
        cout << T_dp[N] << '\n';


    return 0;

}