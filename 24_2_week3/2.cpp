// 치즈 bj.2636
#include <iostream>
#include <queue>
#include <utility>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};
int n, m, cheese, hour;

void check_air(int visited[][101], int board[][101])
{
	queue<pair<int, int> > queue;
	int x, y;

	queue.push(make_pair(0, 0));
	while (!queue.empty())
	{
		y = queue.front().first;
		x = queue.front().second;
		for (int k=0; k<4; k++) {
			if (y + dy[k] >= n || y + dy[k] < 0 || x + dx[k] >= m || x + dx[k] < 0)
				continue;
			if (visited[y + dy[k]][x + dx[k]] == 0 && board[y + dy[k]][x + dx[k]] == 0)
			{
				visited[y + dy[k]][x +dx[k]] = 1;
				queue.push(make_pair(y + dy[k], x + dx[k]));
			}
		}
		queue.pop();
	}
}

int is_possible(int board[][101], int visited[][101], int i, int j)
{
	for (int k=0; k<4; k++) {
		if (i + dy[k] >= n || i + dy[k] < 0 || j + dx[k] >= m || j + dx[k] < 0)
			continue;
		if (board[i + dy[k]][j + dx[k]] == 0 && visited[i + dy[k]][j + dx[k]] == 1)
			return (1);
	}
	return (0);
}

int check_cheese(int board[][101])
{
	int count;

	while (cheese > 0) {
		int visited[101][101] = {0, };

		count = cheese;
		visited[0][0] = 1;
		check_air(visited, board);
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++)
			{
				if (board[i][j] == 1 && is_possible(board, visited, i, j))
				{
					board[i][j] = 0;
					cheese--;
				}
			}
		}
		hour++;
	}
	return (count);
}

int main()
{
	fast;
	int board[101][101], result;

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1) cheese++;
		}
	}
	result = check_cheese(board);
	cout << hour << '\n' << result;
	return (0);
}
