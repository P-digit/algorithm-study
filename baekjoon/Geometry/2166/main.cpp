/* psuedo code
1. 점의 위치를 다 받는다.
2. 원점으로부터 두 점의 ccw값을 계속 더한다
3. 절대값 처리 후 2로 나눈다

T_점

결과값
for(i=1부터->N까지){
    x1, y1은 원점, x2, y2와 x3, y3는 입력받은 점
    결과값 += CCW
}

절대값 처리 후 2.0으로 나눔


*/

#include <iostream>

using namespace std;

typedef pair<double, double> Coord;

static Coord T_coord[10001];

static int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i = 1; i<=N; ++i) {
        int x, y;
        cin >> x >> y;
        T_coord[i] = Coord {x, y};
    }

    double x1 = 0;
    double y1 = 0;
    double result = 0;
    for(int i = 1; i<=N; ++i) {
        double x2, y2, x3, y3;
        if(i == N) {
            x3 = T_coord[1].first;
            y3 = T_coord[1].second;
        }
        else {
            x3 = T_coord[i+1].first;
            y3 = T_coord[i+1].second;
        }
        
        x2 = T_coord[i].first;
        y2 = T_coord[i].second;


        result += ((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));
    }
    

    result = abs(result) / 2.0;
    cout << fixed;
    cout.precision(1);
    cout << result;

    return 0;

}

