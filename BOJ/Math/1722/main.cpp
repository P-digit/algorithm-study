/* pseudo code
T_cases[N] : 순열 경우의 수 배열
T_used[N] : 해당 숫자 사용여부
T_cases[N] = 1;

for(N 역순) {
    T_cases[N-j] = (j+1) * T_cases[N+1-j] 
    }

void getOrder

void getNum(K) {
    int cur_num;
    int K = K - 1;
    for(i = 1부터)
        int count = 0;
        int pos = K / T_cases[i];
        

        for(j = 0부터) {
            if(사용한 숫자) {
                continue
                }
            if(사용 안 한 숫자)
                if(count == pos) {
                    cur_num = j+1;
                    T_used = true;
                    break;
                }
                else {
                    ++count;
                }

    }
    K = K % T_cases[i];

}

*/

#include <iostream>

using namespace std;

void getOrder();
void getNum();

static long long T_cases[21] {};
static bool T_used[21] {};
static int T_data[21] {};

static long long K;
static int N;

int main() {
    cin >> N;

    T_cases[N] = 1;
    fill(&T_used[0], &T_used[21], false);
    for(int i = 1; i < N; ++i) {
        T_cases[N-i] = (i+1) * T_cases[N-i+1];
    }
    
    int cmd;
    cin >> cmd;
    if(cmd == 1) {
        cin >> K;
        if(N==1) {
            cout << 1;
        }
        else {
            getNum();
        }
    }
    else {
        for(int i = 1; i<=N; ++i) {
            cin >> T_data[i];
            
        }
        getOrder();
    }

    return 0;
}

void getNum() {
    int cur_num;
    
    K = K - 1;
    for(int i = 1; i < N; ++i) {
        long long chk = 0;
        long long pos = K / T_cases[i+1];
        
        for(int j = 1; j <= N; ++j) {
            if(!T_used[j]) {
                if(chk == pos) {
                    cur_num = j;
                    T_used[j] = true;
                    break;
                }
                else {
                    ++chk;
                }
            }
        }
        cout << cur_num << ' ';
        K = K % T_cases[i+1];
    }
    for(int i = 1; i<=N; ++i) {
        if(!T_used[i]) cout << i;
    }
    
}

void getOrder() {
    long long pos = 1;
    for(int i = 1; i < N; ++i) {
        int cnt = 0;
        int cur_num = T_data[i];

        for(int j = 1; j < cur_num; ++j) {
            if(!T_used[j]) {
                ++cnt;
                
            }
        }
        pos += (cnt * T_cases[i+1]);
        T_used[cur_num] = true;
    }

    cout << pos;
}