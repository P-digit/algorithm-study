/* psuedo code
1. M : 색, K : 뽑을 개수
T[M] : 색상 공의 개수

result : 결과
for(M) {
    cur_total = 1
    for(K) {
        cur_total *= (현재 색상의 공) / (전체 색상의 공);
        현재 색상의 공 - 1;
        전체 색상의 공 - 1; 
    }
        result += cur_total;
}

result 출력

*/

#include <iostream>
#include <vector>

using namespace std;

static vector <int> T_balls {};
static int N;
static int M;
static int K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> M;
    
    T_balls.resize(M);
    for(int i = 0; i<M; ++i) {
        cin >> T_balls[i];
        N += T_balls[i];
    }
    
    cin >> K;

    double result = 0;
    for(int i = 0; i<M; ++i) {
        double cur_total = 1;
        for(int j = 0; j<K; ++j) {
            cur_total *= ((double)(T_balls[i] - j)/ (N - j));
        }
        result += cur_total;
    }

    cout.precision(9);
    cout << result;
    return 0;

}