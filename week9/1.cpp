// 유기농 배추 bj.1012
#include <iostream>
#include <stack>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

typedef struct s_pos {
    int y;
    int x;
    s_pos(int n1, int n2) {
        y = n1;
        x = n2;
    }
} t_pos;

void dfs(int arr[][50], int visited[][50], int n, int m, int start_y, int start_x)
{
    stack<t_pos> s;
    int y, x, i;

    s.push({start_y, start_x});
    while (!s.empty()) {
        y = s.top().y;
        x = s.top().x;
        visited[y][x] = 1;

        for (i=0; i<4; i++) {
            if (y + dy[i] < 0 || y + dy[i] >= n) continue ;
            if (x + dx[i] < 0 || x + dx[i] >= m) continue ;
            if (visited[y+dy[i]][x+dx[i]] == 0 && arr[y+dy[i]][x+dx[i]] == 1) break ;
        }
        if (i < 4) s.push({y+dy[i], x+dx[i]});
        else s.pop();
    }
}

int count_bugs(int arr[][50], int visited[][50], int n, int m)
{
    int cnt=0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (visited[i][j] == 0 && arr[i][j] == 1) {
                dfs(arr, visited, n, m, i, j);
                cnt++;
            }
        }
    }
    return (cnt);
}

int main()
{
    fast;
    int t, m, n, k, y, x;

    cin >> t;
    for (int i=0; i<t; i++) {
        int arr[50][50] = {0, };
        int visited[50][50] = {0, };

        cin >> m >> n >> k;
        for (int j=0; j<k; j++) {
            cin >> x >> y;
            arr[y][x] = 1;
        }
        cout << count_bugs(arr, visited, n, m) << '\n';
    }
    return (0);
}