#include <iostream>
#include <vector>
#include <string>

using namespace std;

string names[100];
int needs[100];
int volumes[100];
int cache[100][1000];

int N, M;

int pack(int cur, int rest) {
    if(rest == 0 || cur == N ) return 0;

    int & ret = cache[cur][rest]; 
    if(ret != -1) return ret;

    ret = pack(cur+1, rest);
    if(rest >= volumes[cur]) ret = max(ret, needs[cur] + pack(cur+1, rest - volumes[cur]));

    return ret;
}

void reconstruct(int cur, int rest, vector<string> & ret) {
    if(cur == N || rest == 0) return ;
    if(pack(cur, rest) != pack(cur+1, rest)) {
        ret.push_back(names[cur]);
        reconstruct(cur+1, rest - volumes[cur], ret);
    }
    else {
        reconstruct(cur+1, rest, ret);
    }
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int C;

    cin >> C;

    while(C > 0) {
        cin >> N >> M;
        
        fill(&cache[0][0], &cache[0][0] + 100 * 1000, -1);

        for(int i=0; i < N; ++i) {
            cin >> names[i] >> volumes[i] >> needs[i];
        }

        vector <string> selected;
        int ret;

        ret = pack(0, M);
        reconstruct(0, M, selected);

        cout << ret << " " << selected.size() << endl;

        for(auto item : selected) {
            cout << item << endl;
        }
        --C;
    }
    return 0;
}