/* psuedo code
1. 인접리스트로 연결된 노드 저장
2. 루트노드부터 bfs를 수행해 노드의 부모노드, 부모노드의 depth 저장
3. 두 노드의 부모노드 깊이를 동일하게 두고, 같을 때까지 부모노드 탐색

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static vector <vector<int>> T_node;
static vector <int> T_depth;
static vector <int> T_parent;
static vector <bool> T_visited;

int executeLCA(int a, int b);

void bfs(int root);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    
    T_node.resize(N+1);
    T_depth.resize(N+1);
    T_parent.resize(N+1);
    T_visited.resize(N+1);

    for(int i = 0; i < N-1; ++i) {
        int a, b;
        cin >> a >> b;

        T_node[a].push_back(b);
        T_node[b].push_back(a);

    }

    bfs(1);

    int M;
    cin >> M;

    for(int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        cout << executeLCA(a, b) << '\n';
    }

    return 0;
}

void bfs(int root) {

    queue <int> myqueue;
    myqueue.push(root);
    T_visited[root] = true;
    int count = 0;
    int depth = 1;
    int total_nodes = 1;

    while(!myqueue.empty()) {
        int cur = myqueue.front();
        myqueue.pop();

        for(int &node: T_node[cur]) {
            if(!T_visited[node]) {
                T_parent[node] = cur;
                T_depth[node] = depth;
                myqueue.push(node);
                T_visited[node] = true;

            }
        }

        ++count;

        if(count == total_nodes) {
            count = 0;
            total_nodes = myqueue.size();
            ++depth;
        }
    }

}

int executeLCA(int a, int b) {

    if(T_depth[a] > T_depth[b]) {
        int temp = a;
        a = b;
        b = temp;
    }

    while(T_depth[a] != T_depth[b]) {
        b = T_parent[b];
    }
    
    while(a != b) {
        a = T_parent[a];
        b = T_parent[b];
    }

    return a;
}