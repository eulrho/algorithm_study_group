// 알파벳 bj.1987
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

int dfs(char b[][21], int v[], int i, int j, int r, int c)
{
    int temp1, temp2 = 1;

    v[b[i][j] - 'A']++;
    for (int k=0; k<4; k++)
    {
        if (i + dy[k] >= 0 && i + dy[k] < r && j + dx[k] >= 0 && j + dx[k] < c) {
            if (v[b[i + dy[k]][j + dx[k]] - 'A'] == 0)
            {
                temp1 = dfs(b, v, i + dy[k], j + dx[k], r, c) + 1;
                if (temp2 < temp1)
                    temp2 = temp1;
            }
        }
    }
    v[b[i][j] - 'A']--;
    return (temp2);
}

int main()
{
    fast;
    int r, c;
    char alphabet;
    int visited[26] = {0, };
    char board[21][21];

    cin >> r >> c;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cin >> alphabet;
            board[i][j] = alphabet;
        }
    }
    cout << dfs(board, visited, 0, 0, r, c);
    return (0);
}