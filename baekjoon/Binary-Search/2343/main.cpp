/* pseudo code
1. 레슨 길이 최대값부터 총 레슨 길이 사이 최적의 블루레이 크기를 이진 검색으로 찾기

합계
for(i=0부터 N까지) {
    T_time[레슨 시간 저장]
    합계 += 현재 레슨 시간
}

while(s <= e) {
    mid = 중간값;
    
    블루레이 개수
    for(i=0부터 N까지)
        순서대로 합계 계산 
        if(합계 > 중간값) 블루레이 개수 ++
    if(블루레이 개수 < 지정 개수)
        e = mid - 1;
    else(블루레이 개수 > 지정 개수)
        s = mid + 1;
}

*/

#include <iostream>
#include <vector>

using namespace std;

static vector <int> T_time {};

static int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    

    int s, e {};
    for(int i = 0; i<N; ++i) {
        int cur;
        cin >> cur;
        T_time.push_back(cur);

        e += cur;
        s = max(s, cur);
    }

    
    while(s <= e) {
        int mid = (s + e) / 2;

        int spare = mid;
        int count = 1;
        for(int i = 0; i<N; ++i) {
            spare = spare - T_time[i];

            if(spare < 0) {
                spare = mid - T_time[i];
                count ++;
            }
            else if (spare == 0) {
                spare = mid;
                count ++;
            }
        }
        if(count > M) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }

    cout << e;


    return 0;

}