// 중량제한 bj.1939
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int max_weight=0;
int fac_a;
int fac_b;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return (a.first < b.first);
}

void sort_v(vector<vector<pair<int, int>>> &bridge)
{
    for (auto &b : bridge)
        sort(b.begin(), b.end(), cmp);
}

bool bfs(vector<vector<pair<int, int>>> bridge, int start, int end, int w)
{
    int size, f;
    queue<int> q;
    bool visited[10001] = {false,};

    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        f = q.front();
        if (f == end) return (true);
        size = bridge[f].size();
        for (int i=0; i<size; i++) {
            if (visited[bridge[f][i].first] == false && bridge[f][i].second >= w) {
                visited[bridge[f][i].first] = true;
                q.push(bridge[f][i].first);
            }
        }
        q.pop();
    }
    return (false);
}

int find_target(vector<vector<pair<int, int>>> bridge, int left, int right)
{
    bool temp;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;
        temp = bfs(bridge, fac_a, fac_b, mid);
        if (temp == true) {
            if (mid == max_weight || bfs(bridge, fac_a, fac_b, mid + 1) == false) return (mid);
            else left = mid + 1;
        }
        else right = mid - 1;
    }
    return (0);
}

int main()
{
    fast;
    int n, m, a, b, c;
    cin >> n >> m;

    vector<vector<pair<int, int>>> bridge(n+1);
    for (int i=0; i<m; i++) {
        cin >> a >> b >> c;
        bridge[a].push_back(make_pair(b, c));
        bridge[b].push_back(make_pair(a, c));
        if (c > max_weight) max_weight = c;
    }
    cin >> fac_a >> fac_b;
    sort_v(bridge);
    cout << find_target(bridge, 1, max_weight);;
    return (0);
}