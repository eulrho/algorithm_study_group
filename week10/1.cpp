// 수학은 비대면강의입니다 bj.19532
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int a, b, c, d, e, f, x, y;

    cin >> a >> b >> c >> d >> e >> f;
    if (a == 0 && b != 0) {
        y = c/b;
        x = (f-e*y)/d;
    }
    else {
        y = (a*f-c*d)/(a*e-b*d);
        x = (c-b*y)/a;
    }
    cout << x << ' ' << y;
    return (0);
}