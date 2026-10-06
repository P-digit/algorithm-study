/* pseudo code
1. CCW 공식을 이용, (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)의 값에 따른 방향 판단

val = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
if(val이 양수) 반시계이므로 1 출력
if(val이 0) 일직선이므로 0 출력
if(val이 음수) 시계이므로 -1 출력

*/

#include <iostream>

using namespace std;

int main() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int val = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
    if(val > 0) cout << '1';
    else if (val == 0) cout << '0'; 
    else cout << "-1";

    return 0;
}