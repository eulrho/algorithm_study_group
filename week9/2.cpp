// 치즈 bj.2638
#include <iostream>
#include <stack>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int cnt=0;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

typedef struct s_pos {
    int y;
    int x;
} t_pos;

void dfs(int arr[][100], int visited[][100], int n, int m, int start_y, int start_x)
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
            if (visited[y+dy[i]][x+dx[i]] == 0 && arr[y+dy[i]][x+dx[i]] == 0) break ;
        }
        if (i < 4) s.push({y+dy[i], x+dx[i]});
        else s.pop();
    }
}

bool melt(int arr[][100], int visited[][100], int y, int x)
{
    int air_cnt=0;
    for (int i=0; i<4; i++) {
        if (visited[y+dy[i]][x+dx[i]] == 1) air_cnt++;
    }
    if (air_cnt >= 2) arr[y][x] = 0;
    return (air_cnt >= 2);
}

int find_time(int arr[][100], int n, int m)
{
    int time = 0;
    while (cnt > 0) {
        int visited[100][100] = {0, };

        dfs(arr, visited, n, m, 0, 0); // 외부 공기 탐색
        for (int i=1; i<n-1; i++) {
            for (int j=1; j<m-1; j++) {
                if (arr[i][j] == 1 && melt(arr, visited, i, j)) cnt--;
            }
        }
        time++;
    }
    return (time);
}

int main()
{
    fast;
    int n, m;
    int arr[100][100];

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) cnt++;
        }
    }
    cout << find_time(arr, n, m);
    return (0);
}