/* pseudo code
1. - 연산자가 나오면 괄호 열고, 다음 -연산자가 나오거나 수식이 끝나면 닫는다.
2. 해당 수식을 계산한다

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

static string D {};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> D;

    int s = 0;
    int index_cur = 0;
    int result = 0;
    bool n_flag = false;
    while(index_cur<D.size()) {
        char char_cur = D.at(index_cur);
        if(char_cur == '+' || char_cur == '-' || index_cur == D.size() - 1) {
            if(n_flag != true)
            result += stoi(D.substr(s,(index_cur - s)));
            else result -= stoi(D.substr(s,(index_cur - s)));
            if(char_cur == '-') n_flag = true;
            s = index_cur + 1;
        }
        ++index_cur;

    }

    cout << result;

    return 0;
}