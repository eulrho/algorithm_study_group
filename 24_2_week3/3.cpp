// 벽 부수고 이동하기 bj.2206
#include <iostream>
#include <queue>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

typedef struct s_node
{
	int y;
	int x;
	int is_wall;
}	t_node;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};
int n, m;
int visited[2][1001][1001] ={0, };

int bfs(string board[1001])
{
	queue<t_node> queue;
	int y, x, is_wall;

	queue.push({0, 0, 0});
	visited[0][0][0] = 1;
	while (!queue.empty()) {
		y = queue.front().y;
		x = queue.front().x;
		is_wall = queue.front().is_wall;
		for (int k=0; k<4; k++) {
			if (y + dy[k] >= n || y + dy[k] < 0 || x + dx[k] >= m || x + dx[k] < 0)
				continue ;
			if (visited[is_wall][y+dy[k]][x+dx[k]] == 0 && board[y+dy[k]][x+dx[k]] == '0') {
				visited[is_wall][y + dy[k]][x + dx[k]] = visited[is_wall][y][x] + 1;
				queue.push({y + dy[k], x + dx[k], is_wall});
			}
			else if (is_wall == 0 && board[y + dy[k]][x + dx[k]] == '1')
			{
				visited[1][y + dy[k]][x + dx[k]] = visited[is_wall][y][x] + 1;
				queue.push({y + dy[k], x + dx[k], 1});
			}
		}
		queue.pop();
	}
	if (visited[0][n - 1][m - 1] == 0 && visited[1][n - 1][m - 1] == 0)
		return (-1);
	if (visited[1][n - 1][m - 1] == 0)
		return (visited[0][n - 1][m - 1]);
	else
		return (visited[1][n - 1][m - 1]);
}

int main()
{
	fast;
	string board[1001];

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> board[i];
	cout << bfs(board);
	return (0);
}