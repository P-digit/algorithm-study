/* psuedo code
1. 조합 점화식을 이용해 테이블을 채우자.
    T_dp[i][j] = T_dp[i-1][j] + T_dp[i-1][j-1] // 임의의 한 개를 제외 후 j개 뽑기 + 임의의 한 개 포함 후 j-1개 뽑기
*/

#include <iostream>

using namespace std;

static int T_dp[11][11] {};

int main() {
    
    int N, K;
    cin >> N >> K;

    for(int i = 1; i <= 10; ++i) {
        T_dp[i][i] = 1;
        T_dp[i][1] = i;
        T_dp[i][0] = 1; 
    }

    for(int i = 2; i <= 10; ++i) {
        for(int j = 1; j < i; ++j) {
            T_dp[i][j] = T_dp[i-1][j] + T_dp[i-1][j-1];
        }
    }

    cout << T_dp[N][K];

    return 0;
}
