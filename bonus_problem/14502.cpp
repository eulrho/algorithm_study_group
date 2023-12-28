// 연구소
#include <iostream>
#include <utility>
#include <queue>
#define MAX(a, b) (a > b ? a : b);
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int map[10][10];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m;
int max_area, wall;


void find_virus_area(int y, int x, int visited[][10])
{
	queue<pair<int, int>> q;
	int front_x, front_y;

	q.push({y, x});
	while (!q.empty()) {
		front_y = q.front().first;
		front_x = q.front().second;
		for (int k=0; k<4; k++) {
			if (front_y + dy[k] < 0 || front_y + dy[k] >= n || front_x + dx[k] < 0 || front_x + dx[k] >= m)
				continue ;
			if (visited[front_y+dy[k]][front_x+dx[k]] == 0 && (map[front_y+dy[k]][front_x+dx[k]] == 2 || map[front_y+dy[k]][front_x+dx[k]] == 0))
			{
				visited[front_y+dy[k]][front_x+dx[k]] = 1;
				q.push({front_y+dy[k], front_x+dx[k]});
			}
		}
		q.pop();
	}
}

int safe()
{
	int cnt=0;
	int visited[10][10]={0,};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 2 && visited[i][j] == 0)
			{
				visited[i][j] = 1;
				find_virus_area(i, j, visited);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != 1 && visited[i][j] == 0)
				cnt++;
		}
	}
	return (cnt);
}

void create_walls()
{
	if (wall == 3)
	{
		max_area = MAX(safe(), max_area);
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 0) {
					wall++;
					map[i][j] = 1;
					create_walls();
					wall--;
					map[i][j] = 0;
				}
			}
		}
	}
}

int main()
{
	fast;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	create_walls();
	cout << max_area;
	return (0);
}