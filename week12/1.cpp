// 피보나치 함수 bj.1003
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int one[50], zero[50];

void fibonacci(int n) {
    one[1] = 1;
    zero[0] = 1;
    for (int i = 2; i <= n; i++) {
        one[i] = one[i - 1] + one[i - 2];
        zero[i] = zero[i - 1] + zero[i - 2];
    }
}

int main()
{
    fast;
    int t, num;

    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> num;
        fibonacci(num);
        cout << zero[num] << ' ' << one[num] << '\n';
    }
    return (0);
}