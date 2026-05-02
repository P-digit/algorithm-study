/* psuedo code
세그먼트 트리 구현 후 최대값 & 노드값 업데이트

2**k >= N 값 구하기 : start_index
N개의 값 -> 세그먼트 트리로 정렬 및 구간합 업데이트
구간합 출력 start_index, end_index
노드값 업데이트 
연산값은 저장한 첫 노드값 앞부분부터(이전 차수의 가장 오른쪽 노드)
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int findStart(int N);
void changeVal(int from, long long to);
long long calSum(int s_raw, int e_raw);
void updateNode(int target_index);

vector <long long> T_tree;
static int start_index;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    start_index = findStart(N);
    int tree_size = start_index * 2;
    
    T_tree.resize(tree_size, 0);

    for(int i = 0; i<N; ++i) {
        cin >> T_tree[start_index+i];
    }

    // 구간합 정리
    int cur_index = tree_size - 1;
    while(cur_index > 1) {
        int parent_index = cur_index / 2;
        T_tree[parent_index] = T_tree[cur_index - 1] + T_tree[cur_index];
        cur_index -= 2;
    }

    for(int i = 0; i < M + K; ++i) {
        int cmd, le;
        long long ri;
        cin >> cmd >> le >> ri;

        if(cmd == 1) {
            changeVal(le, ri);
        }
        else {
            cout << calSum(le, ri) << '\n';
        }
    }

    return 0;

}

int findStart(int N) {
    int k = 0;
    
    while(pow(2, k) < N) {
        ++k;
    }
    return pow(2, k);

}

void changeVal(int target, long long to) {
    long long tree_index = start_index - 1 + target;
    T_tree[tree_index] = to;
    updateNode(tree_index);
}

void updateNode(int target) {
    int parent = target / 2;
    while(parent >= 1) {
        T_tree[parent] = T_tree[parent * 2] + T_tree[parent * 2 + 1];
        parent /= 2;
    }
}

long long calSum(int s_raw, int e_raw) {
    long long sum {0};
    int s = start_index - 1 + s_raw;
    int e = start_index - 1 + e_raw;

    while(s <= e) {
        if(s % 2 == 1) {
            sum += T_tree[s];
            ++s;
        }

        if(e % 2 == 0) {
            sum += T_tree[e];
            --e;
        }

        s /= 2;
        e /= 2;
    }
    
    return sum;

}