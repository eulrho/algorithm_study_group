// 벌집 bj.2292
#include <iostream>

using namespace std;

int main() {
    int N, result = 0, i = 1;

    cin >> N;
    while (N > 1)
    {
        N = N - 6 * i;
        result++;
        i++;
    }
    result++;
    cout << result;
    return (0);
}