// 숫자의 합 bj.11720
#include <iostream>
#include <string>

using namespace std;

int main() {
    int N, sum = 0;
    string num;

    cin >> N >> num;
    for (int i=0; i<num.size(); i++)
        sum += num[i] - '0';
    cout << sum;
    return (0);
}