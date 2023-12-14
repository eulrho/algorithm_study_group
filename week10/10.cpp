// 감시 bj.15683
#include <iostream>
#include <stack>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

// left, up, right, down
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int map[10][10];
int min_size = 64;
int n, m;

void copy_arr(int visited[][10], int temp[][10])
{
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            temp[i][j] = visited[i][j];
        }
    }
}

void check_blind(int visited[][10])
{
    int cnt=0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (visited[i][j] == 0 && map[i][j] != 6)
                cnt++;
        }
    }
    if (cnt < min_size)
        min_size = cnt;
}

void dfs(int visited[][10], int start_y, int start_x, int pos_y, int pos_x)
{
    int y, x;

    y = start_y;
    x = start_x;
    while (y+pos_y >= 0 && y+pos_y < n && x+pos_x >= 0 && x+pos_x < m && map[y+pos_y][x+pos_x] != 6)
    {
        y = y+pos_y;
        x = x+pos_x;
        if (map[y][x] == 0)
            visited[y][x] = 1;
    }
}

void cctv(int visited[][10], int cctv_cnt)
{
    int temp[10][10];

    if (cctv_cnt == 0) {
        check_blind(visited);
        return ;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (visited[i][j] == 0 && map[i][j] == 1) {
                visited[i][j] = 1;
                for (int k=0; k<4; k++) {
                    if (i + dy[k] < 0 || i + dy[k] >= n || j + dx[k] < 0 || j + dx[k] >= m)
                        continue ;
                    copy_arr(visited, temp);
                    dfs(temp, i, j, dy[k], dx[k]);
                    cctv(temp, cctv_cnt - 1);
                }
            }
            else if (visited[i][j] == 0 && map[i][j] == 2) {
                visited[i][j] = 1;
                for (int k=0; k<2;k++) {
                    copy_arr(visited, temp);
                    dfs(temp, i, j, dy[k], dx[k]);
                    dfs(temp, i, j, dy[k + 2], dx[k + 2]);
                    cctv(temp, cctv_cnt - 1);
                }
            }
            else if (visited[i][j] == 0 && map[i][j] == 3) {
                visited[i][j] = 1;
                for (int k=0; k<4;k++) {
                    copy_arr(visited, temp);
                    dfs(temp, i, j, dy[k], dx[k]);
                    dfs( temp, i, j, dy[(k + 1) % 4], dx[(k + 1) % 4]);
                    cctv( temp, cctv_cnt - 1);
                }
            }
            else if (visited[i][j] == 0 && map[i][j] == 4) {
                visited[i][j] = 1;
                for (int k=0; k<4;k++) {
                    copy_arr(visited, temp);
                    dfs(temp, i, j, dy[k], dx[k]);
                    dfs(temp, i, j, dy[(k + 1) % 4], dx[(k + 1) % 4]);
                    dfs( temp, i, j, dy[(k + 2) % 4], dx[(k + 2) % 4]);
                    cctv( temp, cctv_cnt - 1);
                }
            }
            else if (visited[i][j] == 0 && map[i][j] == 5) {
                visited[i][j] = 1;
                copy_arr(visited, temp);
                for (int k=0; k<4;k++)
                    dfs(temp, i, j, dy[k], dx[k]);
                cctv( temp, cctv_cnt - 1);
            }
        }
    }
}

int main()
{
    fast;
    int cctv_cnt=0;
    int visited[10][10]={0,};

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> map[i][j];
            if (map[i][j] != 0 && map[i][j] != 6)
                cctv_cnt++;
        }
    }
    cctv(visited, cctv_cnt);
    cout << min_size;
    return (0);
}