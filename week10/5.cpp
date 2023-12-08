// 한수 bj.1065
#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool check(int num)
{
    string s = to_string(num);
    int size = (int)s.size(), temp;

    temp = s[0] - s[1];
    for (int i=1; i<size-1; i++) {
        if (s[i] - s[i+1] != temp) return (false);
    }
    return (true);
}

int main()
{
    fast;
    int cnt=0, num;

    cin >> num;
    if (num >= 9) cnt += 9;
    else cnt += num;
    for (int i=10; i<=num; i++) {
        if (check(i)) cnt++;
    }
    cout << cnt;
    return (0);
}