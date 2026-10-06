/* psuedo code
T_node : 연결된 노드를 저장하는 인접리스트
T_answer : 각 노드의 부모노드를 저장하는 리스트
T_visited : 이미 방문한 노드인지 확인하는 테이블

for(T_node 사이즈) {
    노드 1부터 연결된 노드를 dfs 수행. 부모노드를 T_answer에 저장하고 자식노드를 탐색
}

for(N) {
    순차적으로 부모노드 cout
}


*/

#include <iostream>
#include <vector>

using namespace std;

void dfs(int num);

vector <vector <int>> T_node;
vector <int> T_answer;
vector <bool> T_visited;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;

    T_node.resize(N+1);
    T_answer.resize(N+1);
    T_visited.resize(N+1, false);

    for(int i = 0; i < N-1; ++i) {
        int node_a, node_b;

        cin >> node_a >> node_b;

        T_node[node_a].push_back(node_b);
        T_node[node_b].push_back(node_a);
    }

    T_visited[1] = true;
    for(int i = 1; i <= N; ++i) {
        dfs(i);
    }

    for(int i = 2; i <= N; ++i) {
        cout << T_answer[i] << '\n';
    }



}

void dfs(int num) {
    for(const int &e : T_node[num]) {
        if(!T_visited[e]) {
            T_answer[e] = num;
            T_visited[e] = true;
            dfs(e);
        }
    }
}