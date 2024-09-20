// 벽 부수고 이동하기 bj.2206
#include <iostream>
#include <queue>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct node {
	int y, x;
	int is_wall;
};

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int visited[1001][1001][2];

int bfs(int n, int m, string array[])
{
	queue<node> queue;
	int x, y, status;

	queue.push({1, 1, 0});
	visited[1][1][0] = 1;
	visited[1][1][0] = 1;

	while (!queue.empty()) {
		y = queue.front().y;
		x = queue.front().x;
		status = queue.front().is_wall;
		queue.pop();
		for (int k=0; k<4; k++) {
			if (y + dy[k] < 1 || y + dy[k] > n || x + dx[k] < 1 || x + dx[k] > m) continue ;
			if (visited[y + dy[k]][x + dx[k]][status] == 0 && array[y + dy[k]][x + dx[k]] == '0')
			{
				visited[y + dy[k]][x + dx[k]][status] = visited[y][x][status] + 1;
				queue.push({y+dy[k], x+dx[k], status});
			}
			else if (status == 0 && visited[y + dy[k]][x + dx[k]][1] == 0 && array[y + dy[k]][x + dx[k]] == '1')
			{
				visited[y + dy[k]][x + dx[k]][1] = visited[y][x][status] + 1;
				queue.push({y+dy[k], x+dx[k], 1});
			}
		}
	}
	if (visited[n][m][1] != 0) return visited[n][m][1];
	if (visited[n][m][0] != 0) return visited[n][m][0];
	return -1;
}

int main()
{
	fast;
	int n, m;
	string array[1001];

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> array[i];
		array[i] = " " + array[i];
	}
	cout << bfs(n, m, array);
	return 0;
}