// 하노이 탑 이동 순서 bj.11729
#include <iostream>
#include <vector>
#include <utility>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int cnt=0;

void hanoitower(int num, int from, int by, int to, vector<pair<int, int>> &v)
{
    if (num > 1)
        hanoitower(num-1, from, to, by, v);
    cnt++;
    v.push_back(make_pair(from, to));
    if (num > 1)
        hanoitower(num-1, by, from, to, v);
}

int main()
{
    fast;
    int n;
    vector<pair<int, int>> result;
    cin >> n;
    hanoitower(n, 1, 2, 3, result);
    cout << cnt << '\n';
    for (int i=0; i<cnt; i++) {
        cout << result[i].first << ' ' << result[i].second;
        if (i != cnt-1) cout << '\n';
    }
    return (0);
}