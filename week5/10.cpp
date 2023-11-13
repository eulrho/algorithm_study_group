// 벽 부수고 이동하기 bj.2206
#include <iostream>
#include <string>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

typedef struct node {
    int y;
    int x;
    bool break_wall;
    node(int a, int b, bool c) {
        y = a;
        x = b;
        break_wall = c;
    }
}t_node;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs(string g[], int r[][1001], int N, int M)
{
    bool visited[2][1001][1001] = {false, };
    queue<t_node> q;
    int pos_y, pos_x;

    q.push(node(0, 0, false));
    while (q.size())
    {
        pos_y = q.front().y;
        pos_x = q.front().x;
        if (pos_y == N - 1 && pos_x == M - 1) return ;
        for (int i=0; i<4; i++) {
            if (pos_y + dy[i] >= 0 && pos_y + dy[i] < N && pos_x + dx[i] >= 0 && pos_x + dx[i] < M) {
                if (q.front().break_wall == false && visited[0][pos_y + dy[i]][pos_x + dx[i]] == false) {
                    if (g[pos_y + dy[i]][pos_x + dx[i]] == '0') {
                        q.push(node(pos_y + dy[i], pos_x + dx[i], q.front().break_wall));
                    }
                    else if (g[pos_y + dy[i]][pos_x + dx[i]] == '1' && q.front().break_wall == false) {
                        q.push(node(pos_y + dy[i], pos_x + dx[i], true));
                    }
                    else continue;
                    visited[0][pos_y + dy[i]][pos_x + dx[i]] = true;
                    r[pos_y + dy[i]][pos_x + dx[i]] = r[pos_y][pos_x] + 1;
                }
                else if (q.front().break_wall == true && visited[1][pos_y + dy[i]][pos_x + dx[i]] == false) {
                    if (g[pos_y + dy[i]][pos_x + dx[i]] == '0') {
                        q.push(node(pos_y + dy[i], pos_x + dx[i], q.front().break_wall));
                        visited[1][pos_y + dy[i]][pos_x + dx[i]] = true;
                        r[pos_y + dy[i]][pos_x + dx[i]] = r[pos_y][pos_x] + 1;
                    }
                }
            }
        }
        q.pop();
    }
}

int main()
{
    fast;
    int N, M;
    string grid[1001];
    int route[1001][1001] = {1, };

    cin >> N >> M;
    for (int i=0; i<N; i++) {
        cin >> grid[i];
    }
    bfs(grid, route, N, M);
    if (route[N - 1][M - 1] == 0) cout << -1;
    else cout << route[N - 1][M - 1];
    return (0);
}