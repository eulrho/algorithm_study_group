// 좌표 압축 bj.18870
#include <iostream>
#include <map>
#include <utility>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, x, idx=0;
    map<int, int> m;
    cin >> n;
    int origin_position[1000001];

    for (int i=0; i<n; i++) {
        cin >> x;
        origin_position[i] = x;
        if (m.find(x) == m.end())
            m.insert(make_pair(x, 0));
    }
    for (auto &mm : m) {
        mm.second = idx;
        idx++;
    }
    for (int i=0; i<n; i++) cout << m[origin_position[i]] << ' ';
    return (0);
}