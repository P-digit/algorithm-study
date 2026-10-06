/*pseudo code
1. CCW로 교차한 선분 여부 파악
2. 교차하면 union-find로 그룹으로 연결
3. 모든 선분을 탐색해 그룹 개수 및 멤버 수 집계 -> 출력

T[선분 정보]
T[부모 선분]
T[그룹의 멤버수]

구조체 선, 점 정의

유니온, 파인드 함수
for(i=1부터N까지) {
    for(j=i+1부터 N까지)
        if(서로 그룹이 다르고) && if(CCW을 통해 선분이 교차한다)
            union(i, j);
}


for(i=1부터N까지) {
    T[부모선분]의 값으로 그룹의 멤버수 ++
}

int 그룹수;
int 그룹멤버최대값
for(i=1부터N까지) {
    최대값 찾기
    if(T[멤버수]의 값이 0이 아니면)
        그룹수 ++
}

출력


*/

#include <iostream>
#include <numeric>

using namespace std;

struct Point {
    int x, y;

    bool operator >=(const Point &rhs) const {
        if(x == rhs.x) return y >= rhs.y;
        return x >= rhs.x;
    }
};

struct Line {
    Point s, e;
};

static void unionFunc(int a, int b);
static int findFunc(int num);
static int getCCW(Point &p1, Point &p2, Point &p3);
static bool isCross(Line &a, Line &b);

static Line T_line[3001];
static int T_parent[3001];
static int T_member[3001] {};

static int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    iota(&T_parent[0], &T_parent[N+1], 0);

    for(int i=1; i<=N; ++i) {

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        Point s {x1, y1};
        Point e {x2, y2};

        if(s >= e) swap(s, e);

        Line cur_line {s, e};

        T_line[i] = cur_line;

    }

    for(int i=1; i<=N-1; ++i) {
        for(int j=i+1; j<=N; ++j) {
            if(findFunc(i) != findFunc(j) && isCross(T_line[i], T_line[j])) {
                unionFunc(i, j);
            }
        }
    }

    for(int i = 1; i<=N; ++i) {
        T_member[findFunc(T_parent[i])] += 1;
    }

    int group_num = 0;
    int max_members = -1;
    for(int i = 1; i<=N; i++) {
        if(T_member[i] != 0) {
            group_num++;
        }
        max_members = max(max_members, T_member[i]);
    }

    cout << group_num << '\n' << max_members;

    return 0;
}

static int getCCW(Point &p1, Point &p2, Point &p3) {
    int val = (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);

    if(val > 0) return -1;
    if(val == 0) return 0;
    else return 1;

}

static bool isCross(Line &a, Line &b) {
    int val1 = getCCW(a.s, a.e, b.s);
    int val2 = getCCW(a.s, a.e, b.e);
    int val3 = getCCW(b.s, b.e, a.s);
    int val4 = getCCW(b.s, b.e, a.e);

    int ccw12 = val1 * val2;
    int ccw34 = val3 * val4;

    if(ccw12 == 0 && ccw34 == 0) {
        Point p1 = a.s; Point p2 = a.e; Point p3 = b.s; Point p4 = b.e;
    
        if(p4 >= p1 && p2 >= p3) {
            return true;
        }
        else return false;
    }
    else if(ccw12 <= 0 && ccw34 <= 0) {
        return true;
    }
    else return false;
}

static void unionFunc(int a, int b) {
    int parent_a = findFunc(a);
    int parent_b = findFunc(b);

    if(parent_a > parent_b) swap(parent_a, parent_b);

    T_parent[parent_b] = parent_a;

}
static int findFunc(int num) {
    if(T_parent[num] == num) return num;
    return T_parent[num] = findFunc(T_parent[num]);
}