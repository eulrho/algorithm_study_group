// 영단어 암기는 괴로워 bj.20920
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

using namespace std;

bool comp(pair<string, int>& a, pair<string, int>& b)
{
    if (a.second != b.second)
        return (a.second > b.second);
    else if (a.first.size() != b.first.size())
        return (a.first.size() > b.first.size());
    else
        return (a.first < b.first);
}

int main()
{
    fast;
    int N, M;
    string str;

    unordered_map<string, int> m;
    cin >> N >> M;
    for (int i=0; i<N; i++)
    {
        cin >> str;
        if (str.size() >= M)
        {
            if (m.find(str) != m.end())
                m[str]++;
            else
                m.insert(make_pair(str, 1));
        }
    }
    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), comp);
    for (auto vv : v)
        cout << vv.first << '\n';
    return (0);
}