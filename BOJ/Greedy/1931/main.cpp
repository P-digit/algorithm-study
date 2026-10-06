/* pseudo code
// 회의시간의 상한이 없다
1. 종료시간을 기준으로 오름차순 정렬 (같은 종료시간일 때는 빠른 시작시간)
2. 우선순위 큐에서 pop해 현재 시간을 지난 회의일 경우 무시, 가능하면 카운트 추가, 현재 시간 재정의
3. 
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct meeting {
    int s, e;

    bool operator > (const meeting & rhs) const {
        if(e == rhs.e) return s > rhs.s;
        return e > rhs.e;
    }
} meeting;


priority_queue <meeting, vector <meeting>, greater<meeting>> pq;

static int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i=0; i<N; ++i) {
        int s, e;
        cin >> s >> e;
        pq.push(meeting {s, e});
    }

    int time_cur {0};
    int count {0};
    while(pq.empty() != true) {
        meeting meeting_cur = pq.top();
        pq.pop();
        
        if(meeting_cur.s >= time_cur) {
            ++count;
            time_cur = meeting_cur.e;
        }
    }

    cout << count;

    return 0;
}
