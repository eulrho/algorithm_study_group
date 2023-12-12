// 오목 bj.2615
#include <iostream>
#include <utility>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int dfs_dx[4] = {0, 1, 1, 1};
int dfs_dy[4] = {1, 1, 0, -1};

bool check(int board[][20], int y, int x, int num)
{
    if (y < 1 || y > 19 || x < 1 || x > 19)
        return (true);
    if ((board[y][x] == 1 || board[y][x] == 2) && board[y][x] == num)
        return (false);
    else return (true);
}

int dfs(int board[][20], int start_y, int start_x, int dy, int dx)
{
    int num = board[start_y][start_x];
    int y, x, cnt=0;

    y = start_y;
    x = start_x;
    while (1)
    {
        cnt++;
        if (y+dy >= 1 && y+dy <=19 && x+dx >= 1 && x+dx <=19 && board[y+dy][x+dx] == num)
        {
            y = y+dy;
            x = x+dx;
        }
        else
            return (cnt == 5);
    }
}

int main(void)
{
    fast;
    int board[20][20];
    int dx[4] = {0, -1, -1, -1};
    int dy[4] = {-1, -1, 0, 1};

    for (int i=1; i < 20; i++) {
        for (int j=1; j < 20; j++) {
            cin >> board[i][j];
        }
    }
    for (int i=1; i < 20; i++) {
        for (int j=1; j < 20; j++) {
            for (int k=0; k<4; k++) {
                if (board[i][j] != 0 && check(board, i+dy[k], j+dx[k], board[i][j]) == 1) {
                    if (dfs(board, i, j, dfs_dy[k], dfs_dx[k]) == 1) {
                        cout << board[i][j] << '\n' << i << ' ' << j;
                        return (0);
                    }
                }
            }
        }
    }
    cout << 0;
    return (0);
}