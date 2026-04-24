#include <iostream>

using namespace std;

int main()
{
    int sum{0};
    int N{};
    string numbers;

    cin >> N;
    cin >> numbers;

    for (int i = 0; i < numbers.length(); i++)
    {
        sum += numbers[i] - '0';
    }
    cout << sum << "\n";
}