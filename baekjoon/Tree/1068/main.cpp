/* pseudo code
인접리스트로 부모-자식 관계 정리
루트노드부터 dfs 수행, 리프노드일 시 count += 1
제거 노드일시에 해당 노드로부터의 dfs는 수행 x

*/

#include <iostream>
#include <vector>


using namespace std;

void dfs(int num, int removed_node);

vector <vector <int>> T_node;
vector <bool> T_visited;

int count {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    T_node.resize(N);
    T_visited.resize(N, false);

    for(int i = 0; i < N; ++i) {
        int root_node;
        cin >> root_node;

        if(root_node == -1) continue;

        T_node[root_node].push_back(i);

    }

    int removed_node {};
    cin >> removed_node;
    
    dfs(0, removed_node);

    cout << count;

    return 0;

}

void dfs(int num, int removed_node) {
    if(num != removed_node) {
        if(T_visited[num] != true) {
            if(T_node[num].empty()) {
                ++count;
                T_visited[num] = true;
            }
            else {
                for(int &child : T_node[num]) {
                    dfs(child, removed_node);
                    T_visited[child] = true;
                }
            }
        }
    }

}