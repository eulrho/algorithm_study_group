// 경로 찾기 bj.11403
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void sort_v(vector<vector<int>> &v, int N)
{
    for (int i=0; i<N; i++)
        sort(v[i].begin(), v[i].end());
}

int bfs(vector<vector<int>> v, int N, int start, int end)
{
    vector<int> visited(N, 0);
    queue<int> q;
    int cnt=0;

    q.push(start);
    while (q.size())
    {
        if (cnt != 0 && q.front() == end)
            return (1);
        visited[q.front()]++;
        cnt++;
        for (int i=0; i<v[q.front()].size(); i++)
            if (visited[v[q.front()][i]] < 2) q.push(v[q.front()][i]);
        q.pop();
    }
    return (0);
}

int main()
{
    fast;
    int N, edge;
    cin >> N;
    vector<vector<int>> nodes(N);

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> edge;
            if (edge == 1)
                nodes[i].push_back(j);
        }
    }
    sort_v(nodes, N);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << bfs(nodes, N, i, j);
            if (j < N - 1) cout << ' ';
        }
        if (i < N - 1) cout << '\n';
    }
    return (0);
}