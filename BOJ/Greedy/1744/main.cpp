/* psuedo code
1. 양수 최대우선순위 큐, 음수 최소우선순위 큐에 데이터 저장
2. 개수 두 개 이상 가정, 양수큐 음수큐 절대값 비교 후 최대값이 되도록 설정

pq, nq : 양수큐, 음수큐

N : 개수
int result = 0
for(N번) {
    0은 거른다. 1이면 그냥 더하기
    cur_data가 양수면 : pq push
    cur_data가 음수면 : nq push
}

while(pq.size() > 1) {
    최대값 두 원소 곱해서 더하기
}

while(nq.size() > 1) {
    최소값 두 원소 곱해서 더하기
}

0을 음수값 제거하는 용으로 사용

나머지 그냥 더하기

결과 출력

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static priority_queue <int, vector <int>, greater<int>> nq;
static priority_queue <int, vector <int>> pq;

static int N;
static bool zero;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    int result {};
    for(int i=0; i<N; ++i) {
        int num;
        cin >> num;
        
        if(num == 1) result += 1;
        else if (num == 0) zero = true;
        
        else {
            if(num > 0) pq.push(num);
            else nq.push(num);
        }
    }

    while(pq.size() > 1) {
        int f, s;
        f = pq.top();
        pq.pop();
        s = pq.top();
        pq.pop();

        result += ( f * s );
    }

    if(pq.empty() != true) {
        result += pq.top();
    }

    while(nq.size() > 1) {
        int f, s;
        f = nq.top();
        nq.pop();
        s = nq.top();
        nq.pop();

        result += ( f * s );
    }

    if(nq.empty() != true) {
        if(zero != true) result += nq.top();
    }

    cout << result;

    return 0;

}
