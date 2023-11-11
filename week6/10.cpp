// 하노이 탑 bj.1914
#include <iostream>
#include <cmath>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n;

void hanoitower(int num, int from, int by, int to)
{
    if (num > 1)
        hanoitower(num-1, from, to, by);
    cout << from << ' ' << to << '\n';
    if (num > 1)
        hanoitower(num-1, by, from, to);
}

int main()
{
    fast;
    string big_cnt;

    cin >> n;
    big_cnt = to_string(pow(2, n));
    big_cnt = big_cnt.substr(0, big_cnt.find('.'));
    big_cnt[big_cnt.size()-1]--;
    cout << big_cnt;
    if (n <= 20) {
        cout << '\n';
        hanoitower(n, 1, 2, 3);
    }
    return (0);
}