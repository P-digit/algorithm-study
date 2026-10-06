/* pseudo code
1. 2**k >= N인 값을 찾고 2**k의 두 배 크기인 세그먼트 트리 배열 할당
2. start_index = 2**k 부터 N개의 정수 저장
3. end_index부터 차례대로 최소값을 parent_node에 저장
4. 범위가 주어지면 tree_index로 변환 후 최소값 반환 

T_tree[2**k 두 배]

for(N) {
    start_index부터 차례대로 값 T_tree에 저장
}

현재 인덱스 = 트리 사이즈 - 1 ( 마지막 인덱스 )
while(현재 인덱스 > 1) {
    parent_index = 현재 인덱스 / 2;
    T_tree[부모 노드] = min(T_tree[현재 인덱스], T_tree[현재 인덱스 - 1]);
    현재 인덱스 = 현재 인덱스 - 2
}

범위 내 최소값 구하기
최소값(시작, 끝) {
    트리_시작, 트리_끝
    현재 최소값 = INT_MAX;
    while(시작 <= 끝) {
        if(시작 % 2 == 1) {
            min(현재, 시작);
            시작++
        }
        if(끝 % 2 == 0) {
            min(현재, 끝);
            끝--
        }
        s / 2;
        e / 2;
    }

    return 현재_최소값

}

*/

#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>

using namespace std;

void sortTree();
int findMin(int s_raw, int e_raw);
vector <int> T_tree;

static int start_index;
static int tree_size;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    int k = 0;
    while(pow(2, k) < N) {
        ++k;
    }
    start_index = pow(2, k);
    tree_size = start_index * 2;

    T_tree.resize(tree_size, INT_MAX);

    for(int i = 0; i<N; ++i) {
        cin >> T_tree[start_index + i];
    }

    sortTree();

    for(int i = 0; i<M; ++i) {
        int s, e;
        cin >> s >> e;
        
        cout << findMin(s, e) << '\n';
    }

    return 0;
}

void sortTree() {
    int cur_node = tree_size - 1;
    while(cur_node > 1) {
        int parent_node = cur_node / 2;
        T_tree[parent_node] = min(T_tree[cur_node - 1], T_tree[cur_node]);
        cur_node -= 2;
    }

}

int findMin(int s_raw, int e_raw) {
    int s = start_index - 1 + s_raw;
    int e = start_index - 1 + e_raw;
    int cur_min = INT_MAX;

    while(s <= e) {
        if(s % 2 == 1) {
            cur_min = min(T_tree[s], cur_min);
            ++s;
        }
        if(e % 2 == 0) {
            cur_min = min(T_tree[e], cur_min);
            --e;
        }
        s /= 2;
        e /= 2;
    }

    return cur_min;
}