/* psuedo code
1. dp을 이용해 점화식을 세워 테이블 채우기 (a와 z 두 개를 사전순서로 나열. 앞 문자가 a일 때의 경우 + 앞 문자가 z일 때의 경우)
2. a-i개, b-j개 있는 상황에서 dp[i-1][j] > K이면 k번 째 문자열의 현재 문자는 a. dp[i-1][j] < k 일 경우 앞 문자는 z.
** K는 10억 이하이므로 10억이 넘는 경우의 수라면 10억 + 1 로 표현

long long T_dp[101][101]
for(i->N) {
    for(j->N) {
        if(i 또는 j가 0) {
            T_dp[i][j] = 1;
        }
        else {
            T_dp[i][j] = T_dp[i-1][j] + T_dp[i][j-1];
        }
    }
}

if(K가 dp[a][b]보다 크면) -1 출력
else if {
    count = 0;
    while(count == N+M) {
        if(남은 N 또는 M이 0) {
            나머지 문자열 출력
        }
        else {
            if(문자가 a가 올 때 경우의 수 > K) {
                a출력, 남은 a 감소, 카운트 ++
            }
            else {
                z출력, 남은 z 감소, 카운트++, K = K - 문자가 a가 올 때 경우의 수
            }
        }
    }
}

*/

#include <iostream>

using namespace std;

static int N, M, K;
static long long T_dp[101][101] {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;

    for(int i = 0; i <= 100; ++i) {
        for(int j = 0; j <=100; ++j) {
            if(i == 0 || j == 0) {
                T_dp[i][j] = 1;
            }
            else {
                T_dp[i][j] = T_dp[i-1][j] + T_dp[i][j-1];
                if(T_dp[i][j] > 1000000000) {
                    T_dp[i][j] = 1000000001;
                }
            }
        }
    }

    if(K > T_dp[N][M]) {
        cout << -1;
        return 0;
    }

    int count = 0;
    int cur_N = N;
    int cur_M = M;

    while(count != (N+M)) {
        if(cur_N != 0 && cur_M != 0) {
            long long case_num = T_dp[cur_N-1][cur_M];
            if(case_num >= K) {
                cout << "a";
                --cur_N;
                ++count;
            }
            else {
                cout << "z";
                --cur_M;
                ++count;
                K -= case_num;
            }
        }
        else {
            if(cur_N) {
                for(int i = 0; i<cur_N; ++i) {
                    cout << "a";
                    ++count;
                }
            }
            else {
                for(int i = 0; i<cur_M; ++i) {
                    cout << "z";
                    ++count;
                }
            }
        }
    }

    return 0;

}
