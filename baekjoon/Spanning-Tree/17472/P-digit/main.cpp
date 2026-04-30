#include <iostream>
#include <queue>
#include <limits.h>
#include <numeric>

using namespace std;

typedef struct Edge {
    int s, e, l;

    bool operator > (const Edge &rhs) const {
        return l > rhs.l;
    }
} Edge;

int T_map[101][101] {};
bool T_visited[101][101];
int T_parent[7];
queue <pair<int, int>> myqueue;

int findFunc(int num);
void unionFunc(int a, int b);
bool isPossible(int y, int x, int N, int M) {
    return !(y < 0 || y > N-1 || x < 0 || x > M-1);
}

int main() {
    int N, M;
    cin >> N >> M;

    fill(&T_visited[0][0], &T_visited[0][0] + (101 * 101), false);
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> T_map[i][j];
        }
    }

    int dy[] {1, -1, 0, 0};
    int dx[] {0, 0, -1, 1};

    int nation_num = 1;

    for(int y = 0; y < N; ++y) {
        for(int x = 0; x < M; ++x) {
            if(!T_visited[y][x] && (T_map[y][x])) {
                myqueue.push(make_pair(y, x));
                T_visited[y][x] = true;
                while(!myqueue.empty()) {
                    int cur_y = myqueue.front().first;
                    int cur_x = myqueue.front().second;
                    myqueue.pop();

                    T_map[cur_y][cur_x] = nation_num;
                    
                    for(int i = 0; i < 4; ++i) {
                        int next_y = cur_y + dy[i];
                        int next_x = cur_x + dx[i];
                        if(isPossible(next_y, next_x, N, M)) {
                            if(!T_visited[next_y][next_x] && T_map[next_y][next_x]) {
                                myqueue.push(make_pair(next_y, next_x));
                                T_visited[next_y][next_x] = true;
                            }
                        }
                    }
                }
                ++nation_num;
            }
        }
    }

    priority_queue <Edge, vector <Edge>, greater<Edge>> pq;

    for(int y = 0; y < N; ++y) {
        for(int x = 0; x < M; ++x) {
                if(T_map[y][x]) {
                    int start_nation = T_map[y][x];

                    for(int i = 0; i<4; ++i) {
                        int next_y = y + dy[i];
                        int next_x = x + dx[i];
                        int dist = 0;

                        while(isPossible(next_y, next_x, N, M) && !T_map[next_y][next_x]) {
                            next_y = next_y + dy[i];
                            next_x = next_x + dx[i];
                            ++dist;
                            if(T_map[next_y][next_x]) break;
                            
                        }

                        if(isPossible(next_y, next_x, N, M) && T_map[next_y][next_x] && dist > 1) {
                            pq.push(Edge {start_nation, T_map[next_y][next_x], dist});
                        }
                    }
                }
            }
        }

    int used_edges = 0;
    int result = 0;
    int total_nations = nation_num - 1;
    
    iota(&T_parent[1], (&T_parent[7]), 1);

    while(!pq.empty()) {
        Edge cur_edge = pq.top();
        pq.pop();

        if(findFunc(cur_edge.s) != findFunc(cur_edge.e)) {
            unionFunc(cur_edge.s, cur_edge.e);
            result += cur_edge.l;
            ++used_edges;
        }

        if(used_edges == total_nations - 1) break;
    }

    if(used_edges == (nation_num - 1 - 1)) {
        cout << result;
    }
    else {
        cout << -1;
    }

    return 0;
}

int findFunc(int num) {
    if(T_parent[num] == num) return num;
    return T_parent[num] = findFunc(T_parent[num]);
}

void unionFunc(int a, int b) {
    int parent_a = findFunc(a);
    int parent_b = findFunc(b);

    if (parent_a < parent_b) {
        T_parent[parent_b] = parent_a;
    }
    else {
        T_parent[parent_a] = parent_b;
    }

}