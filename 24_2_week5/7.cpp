// 치즈 bj.2636
#include <iostream>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int cheese_cnt;
int board[100][100];
int h, w;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

void bfs(queue<pair<int, int>> &melting_cheese, int visited[][100])
{
	queue<pair<int, int>> queue;
	int y, x;

	visited[0][0] = 1;
	queue.emplace(0, 0);
	while (!queue.empty()) {
		y = queue.front().first;
		x = queue.front().second;
		queue.pop();
		for (int k=0; k<4; k++) {
			if (y + dy[k] < 0 || y + dy[k] >= h || x + dx[k] < 0 || x + dx[k] >= w)
				continue ;
			if (visited[y+dy[k]][x+dx[k]] == 0 && board[y+dy[k]][x+dx[k]] == 0) {
				visited[y+dy[k]][x+dx[k]] = 1;
				queue.emplace(y+dy[k], x+dx[k]);
			}
			else if (visited[y+dy[k]][x+dx[k]] == 0 && board[y+dy[k]][x+dx[k]] == 1) {
				visited[y+dy[k]][x+dx[k]] = 1;
				melting_cheese.emplace(y+dy[k], x+dx[k]);
			}
		}
	}
}

void cheese()
{
	int time = 0, y, x, cnt=0, temp;
	queue<pair<int, int>> melting_cheese;

	while (cheese_cnt > 0) {
		int visited[100][100] = {0, };

		temp = 0;
		bfs(melting_cheese, visited);
		while (!melting_cheese.empty()) {
			y = melting_cheese.front().first;
			x = melting_cheese.front().second;
			melting_cheese.pop();
			if (board[y][x] == 1) {
				board[y][x] = 0;
				temp++;
			}
		}
		cnt = cheese_cnt;
		cheese_cnt -= temp;
		melting_cheese = queue<pair<int, int>> ();
		time++;
	}
	cout << time << '\n' << cnt;
}

int main()
{
	fast;

	cin >> h >> w;
	for (int i=0; i<h; i++) {
		for (int j=0; j<w; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1) cheese_cnt++;
		}
	}
	cheese();
	return (0);
}