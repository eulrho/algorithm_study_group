// 중앙 이동 알고리즘 bj.2903
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N, result;

    cin >> N;
    result = (pow(2, N) + 1) * (pow(2, N) + 1);
    cout << result;
    return (0);
}