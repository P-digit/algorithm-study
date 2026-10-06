/* pseudo code
1. 우선순위 큐를 이용해 데이터 최소 힙으로 정렬
2. 가장 작은 두 값을 합친 후, 다시 우선순위 큐에 삽입
3. 1~2 반복

pq

N[카드개수]

for(i=0 -> N까지) {
    data -> pq에 push
}

while(pq가 비었을 때까지) {
    두 값을 pop한 후 더한다
    카운트 늘리고, 더한 값을 다시 pq에 push
}

결과 출력

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static int N;
static priority_queue <int, vector <int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;


    for(int i=0; i<N; ++i) {
        int num_card;

        cin >> num_card;
        pq.push(num_card);
    }

    int count = 0;

    while(pq.size() > 1) {
        int f, s;
        f = pq.top();
        pq.pop();
        s = pq.top();
        pq.pop();

        count += (f + s);
        pq.push(f + s);

    }

    cout << count;

    return 0;

}
