// 연구소 bj.14502
#include <iostream>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int board[10][10];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};
int max_safety_zone;

void bfs(int n, int m, int start_y, int start_x, int visited[][10])
{
	queue<pair<int, int> > queue;

	queue.push(make_pair(start_y, start_x));
	while (!queue.empty()) {
		int y = queue.front().first;
		int x = queue.front().second;
		queue.pop();

		for (int k=0; k<4; k++) {
			if (dy[k] + y < 0 || dy[k] + y >= n || dx[k] + x < 0 || dx[k] + x >= m)
				continue ;
			if (visited[dy[k] + y][dx[k] + x] == 0 && board[dy[k] + y][dx[k] + x] != 1) {
				queue.push(make_pair(dy[k] + y, dx[k] + x));
				visited[dy[k] + y][dx[k] + x] = 1;
			}
		}
	}
}

int find_safety_zone(int n, int m)
{
	int visited[10][10] = {0,};

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (visited[i][j] == 0 && board[i][j] == 2) {
				visited[i][j] = 1;
				bfs(n, m, i, j, visited);
			}
		}
	}

	int cnt=0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (visited[i][j] == 0 && board[i][j] == 0) cnt++;
		}
	}
	return cnt;
}

void create_wall(int n, int m, int wall_cnt)
{
	if (wall_cnt == 3) {
		max_safety_zone = max(max_safety_zone, find_safety_zone(n, m));
		return ;
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (board[i][j] == 0) {
				board[i][j] = 1;
				create_wall(n, m, wall_cnt+1);
				board[i][j] = 0;
			}
		}
	}
}

int main()
{
	fast;
	int n, m;
	cin >> n >> m;

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++)
			cin >> board[i][j];
	}
	create_wall(n, m, 0);
	cout << max_safety_zone;
	return 0;
}