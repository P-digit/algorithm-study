/* psuedo code
T_tree[26][2] // 각 노드의 자식노드 저장 트리 배열

전위순회 : 본인노드 먼저 그리고 왼쪽 자식 , 오른쪽 자식 출력
중위순회 : 왼쪽노드 먼저 그리고 본인 노드, 오른쪽 자식 출력
후위순회 : 왼쪽노드 먼저 그리고 오른쪽 자식, 본인 노드

*/

#include <iostream>

using namespace std;

int T_tree[26][2];

void preOrder(int index) {
    if(index == -1) return;

    cout << (char) (index + 'A');
    preOrder(T_tree[index][0]);
    preOrder(T_tree[index][1]);

}

void inOrder(int index) {
    if(index == -1) return;

    inOrder(T_tree[index][0]);
    cout << (char) (index + 'A');
    inOrder(T_tree[index][1]);

}

void postOrder(int index) {
    if(index == -1) return;

    postOrder(T_tree[index][0]);
    postOrder(T_tree[index][1]);
    cout << (char) (index + 'A');

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    fill(&T_tree[0][0], &T_tree[0][0] + 26 * 2, -1);

    
    for(int i=0; i<N; ++i) {
        char root_char, le, ri;
        cin >> root_char >> le >> ri;

        int root = root_char - 'A';
        if(le != '.') {
            T_tree[root][0] = le - 'A';
        }
        if(ri != '.') {
            T_tree[root][1] = ri - 'A';
        }
    }
    
    preOrder(0); cout << '\n';
    inOrder(0); cout << '\n';
    postOrder(0);

    return 0;
}

