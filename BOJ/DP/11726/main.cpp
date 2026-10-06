#include <iostream>
#include <vector>

using namespace std;

static int N;
static vector<long long> DP;
static long long mod = 10007;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    DP.assign(N + 1, 0);

    DP[1] = 1;
    DP[2] = 2;
    for (int i = 3; i <= N; ++i)
    {
        DP[i] = (DP[i - 1] + DP[i - 2]) % mod;
    }

    cout << DP[N];

    return 0;
}