/* pseudo code
1. 가장 큰 동전부터 현재 남아있는 돈을 나눗셈 연산을 해, 몫을 카운트함
2. 나눗셈 연산 후 나머지 값을 이전 동전보다 값이 작은 동전으로 1과 동일한 계산
3. 남아있는 돈이 0이 될 때까지 반복.

*/

#include <iostream>
#include <vector>

using namespace std;

static vector <int> T_coin {};
static int N, K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for(int i=0; i<N; ++i) {
        int cur_coin;
        cin >> cur_coin;
        T_coin.push_back(cur_coin);
    }


    int count {};
    for(int i = N-1; i >=0; --i) {
        int cur_coin = T_coin[i];

        count += ( K / cur_coin);
        K = K % cur_coin;
    }

    cout << count;

    return 0;

}