/* 
2차원 pair 벡터 T_e[V+1]
T_w
visited

for(E)
 T[u].push_back(v, w)

queue.push(first)
while(!queue.empty)
    해당 노드 연결된 엣지 가중치 가장 작은 거 선택
    방문을 했으니 visited[node] = true

for(N)
    최단 경로 print
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair <int, int> edge;


vector <vector <edge>> T_node;
vector <int> T_distance;

const int INF = 987654321;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int V, E;

    cin >> V >> E;

    T_node.resize(V+1);
    T_distance.resize(V+1, INF);

    int start;
    cin >> start;
    T_distance[start] = 0;
    for(int i=0; i<E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;

        T_node[u].push_back(make_pair(v, w));
    }

    priority_queue<edge, vector <edge>, greater<edge>> pq;
    pq.push(make_pair(T_distance[start], start));

    while(!pq.empty()) {
        int cur_dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if(T_distance[cur_node] < cur_dist) {
            continue;
        }

        for(edge e:T_node[cur_node]) {
            int next = e.first;
            int weight = e.second;

            int next_dist = cur_dist + weight;
            if(T_distance[next] > next_dist) {
                pq.push(make_pair(next_dist, next));
                T_distance[next] = next_dist;
            }
            
        }
        
    }

    for(int i=1;i<=V;++i) {
        if(T_distance[i] == INF) {
            cout << "INF" << '\n';
        }
        else {
            cout << T_distance[i] << '\n';
        }
    }

    return 0;
    
}
