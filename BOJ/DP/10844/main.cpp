#include <iostream>
#include <vector>

using namespace std;

static int DP[101][10]{};
static int N;
static int MOD = 1000000000;

int main()
{

    cin >> N;

    for (int i = 1; i <= 9; ++i)
    {
        DP[1][i] = 1;
    }
    for (int i = 2; i <= N; ++i)
    {
        for (int j = 0; j <= 9; ++j)
        {
            if (j == 0)
            {
                DP[i][j] = DP[i - 1][j + 1] % MOD;
            }
            else if (j == 9)
            {
                DP[i][j] = DP[i - 1][j - 1] % MOD;
            }
            else
            {
                DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % MOD;
            }
        }
    }

    int answer{};
    for (int i = 0; i <= 9; ++i)
    {
        answer = (answer + DP[N][i]) % MOD;
    }

    cout << answer;

    return 0;
}