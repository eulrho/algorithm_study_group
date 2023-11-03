// 미로 탐색 bj.2178
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

int bfs(vector<string> v, int N, int M)
{
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    vector<vector<int>> route(N, vector<int>(M, 1));
    queue<pair<int, int>> q;
    int f, s;

    q.push(make_pair(0, 0));
    while (q.size())
    {
        f = q.front().first, s = q.front().second;
        if (f == N - 1 && s == M - 1)
            return (route[N - 1][M - 1]);
        for (int i=0; i<4; i++) {
            if (f + dy[i] >= 0 && f + dy[i] < N && s + dx[i] >= 0 && s + dx[i] < M) {
                if (v[f + dy[i]][s + dx[i]] == '1' && visited[f + dy[i]][s + dx[i]] == false) {
                    visited[f + dy[i]][s + dx[i]] = true;
                    q.push(make_pair(f + dy[i], s + dx[i]));
                    if (route[f + dy[i]][s + dx[i]] == 1 || route[f + dy[i]][s + dx[i]] > route[f][s] + 1)
                        route[f + dy[i]][s + dx[i]] = route[f][s] + 1;
                }
            }
        }
        q.pop();
    }
    return (1);
}

int main()
{
    fast;
    int N, M;
    string str;
    cin >> N >> M;
    vector<string> map;

    for (int i=0; i<N; i++) {
        cin >> str;
        map.push_back(str);
    }
    cout << bfs(map, N, M);
    return (0);
}