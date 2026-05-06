/*
// 2차원 배열 원소 출력
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            cout << T[i][j] << ' ';
        }
        cout << '\n';
    }

// 최소 엣지 구조체
typedef struct Edge {
    int s, e, w;

    bool operator > (const Edge& rhs) const {
        return w > rhs.w;
    }

} Edge;

// 유니온 파인드

void unionFunc(int a, int b) {
    int parent_a = findFunc(a);
    int parent_b = findFunc(b);

    if(parent_a != parent_b) {
        int lo = parent_a < parent_b ? parent_a : parent_b;
        int hi = parent_a > parent_b ? parent_a : parent_b;

        parent[hi] = lo;
    }
}

int findFunc(int num) {
    if(parent[num] == num) return num;
    return parent[num] = findFunc(parent[num]);
}

// cout 소수점 처리
cout << fixed ; 소수점 위치 고정 (없으면 precision 시 소수점 기준이 아닌 숫자 개수 기준)
cout.precision(1); 소수점 아래 개수 설정




*/
