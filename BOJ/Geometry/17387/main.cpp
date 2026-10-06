#include <iostream>
#include <algorithm>

using namespace std;

struct Point {
    long long x, y;
    
    bool operator<=(const Point& other) const {
        if (x == other.x) return y <= other.y;
        return x <= other.x;
    }
};

int getCCW(Point p1, Point p2, Point p3) {
    long long eq = (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
    if (eq > 0) return 1;
    if (eq < 0) return -1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Point p1, p2, p3, p4;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;

    int val1 = getCCW(p1, p2, p3);
    int val2 = getCCW(p1, p2, p4);
    int val3 = getCCW(p3, p4, p1);
    int val4 = getCCW(p3, p4, p2);

    int ccw12 = val1 * val2;
    int ccw34 = val3 * val4;

    if (ccw12 == 0 && ccw34 == 0) {
        if (p2 <= p1) swap(p1, p2);
        if (p4 <= p3) swap(p3, p4);

        if (p1 <= p4 && p3 <= p2) cout << 1;
        else cout << 0;
    }
    else if (ccw12 <= 0 && ccw34 <= 0) {
        cout << 1;
    }

    else {
        cout << 0;
    }

    return 0;
}