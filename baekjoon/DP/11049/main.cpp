#include <iostream>
#include <algorithm>
#include "limits.h"

using namespace std;

typedef pair<int, int> mat;

int N;
int cache[501][501] {};
mat T[501] {};

int getMin(int s, int e) {
    if(s==e) return 0;
    if(s+1 == e) return T[s].first * T[s].second * T[e].second;
    int & ret = cache[s][e];

    if(ret != -1) return ret;
    
    ret = INT_MAX;
    for(int k = s; k < e; ++k) {
        ret = min(ret, getMin(s, k) + getMin(k+1, e) + T[s].first * T[k].second * T[e].second);
    }
    return ret;

}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;

    fill(&cache[0][0], &cache[0][0] + 501 * 501, -1);


    for(int i=1; i<=N; ++i) {
        int f, s;

        cin >> f >> s;

        T[i] = make_pair(f, s);
    }

    cout << getMin(1, N);

    return 0;

}