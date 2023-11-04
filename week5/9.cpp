// 적록색약 bj.10026
#include <iostream>
#include <queue>
#include <utility>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

void case1(char g[][101], bool v[][101], int N, int y, int x)
{
    queue<pair<int, int>> q;
    int f, s;

    q.push(make_pair(y, x));
    v[y][x] = true;
    while (q.size())
    {
        f = q.front().first;
        s = q.front().second;
        for (int i=0; i<4; i++) {
            if (f + dy[i] >= 0 && f + dy[i] < N && s + dx[i] >=0 && s + dx[i] < N)
            {
                if (v[f+dy[i]][s+dx[i]] == false && g[y][x] == g[f+dy[i]][s+dx[i]])
                {
                    q.push(make_pair(f+dy[i], s+dx[i]));
                    v[f+dy[i]][s+dx[i]] = true;
                }
            }
        }
        q.pop();
    }
}

void case2(char g[][101], bool v[][101], int N, int y, int x)
{
    queue<pair<int, int>> q;
    int f, s;

    q.push(make_pair(y, x));
    v[y][x] = true;
    while (q.size())
    {
        f = q.front().first;
        s = q.front().second;
        for (int i=0; i<4; i++) {
            if (f + dy[i] >= 0 && f + dy[i] < N && s + dx[i] >=0 && s + dx[i] < N)
            {
                if (v[f+dy[i]][s+dx[i]] == false)
                {
                    if (g[y][x] == g[f+dy[i]][s+dx[i]] || (g[y][x] == 'R' && g[f+dy[i]][s+dx[i]] == 'G')
                    || (g[y][x] == 'G' && g[f+dy[i]][s+dx[i]] == 'R'))
                    {
                        q.push(make_pair(f+dy[i], s+dx[i]));
                        v[f+dy[i]][s+dx[i]] = true;
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
    int N, common=0, blindness=0;
    char grid[101][101];
    bool visited1[101][101] = {false, };
    bool visited2[101][101] = {false, };

    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            cin >> grid[i][j];
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (visited1[i][j] == false)
            {
                case1(grid, visited1, N, i, j);
                common++;
            }
            if (visited2[i][j] == false)
            {
                case2(grid, visited2, N, i, j);
                blindness++;
            }
        }
    }
    cout << common << ' ' << blindness;
    return (0);
}