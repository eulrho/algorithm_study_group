// 토마토 bj.7576
#include <iostream>
#include <queue>
#include <utility>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};
int visited[1001][1001] = {0, };
int n, m, day;

void bfs(int arr[][1001], queue<pair<int, int> > &tomato)
{
	int y, x;

	while (!tomato.empty()) {
		y = tomato.front().first;
		x = tomato.front().second;
		for (int k=0; k<4; k++) {
			if (y + dy[k] < 0 || y + dy[k] >= n || x + dx[k] < 0 || x + dx[k] >= m)
				continue ;
			if (arr[y + dy[k]][x + dx[k]] == 0)
			{
				tomato.push(make_pair(y + dy[k], x + dx[k]));
				arr[y + dy[k]][x + dx[k]] = 1;
				visited[y + dy[k]][x +dx[k]] = visited[y][x] + 1;
			}
		}
		tomato.pop();
	}
}

int check_tomato(int arr[][1001])
{
	queue<pair<int, int> > tomato;
	int y, x;

	for (int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if (arr[i][j] == 1)
				tomato.push(make_pair(i, j));
		}
	}
	bfs(arr, tomato);
	for (int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if (arr[i][j] == 0)
				return (-1);
			if (arr[i][j] == 1)
				day = day < visited[i][j] ? visited[i][j] : day;
		}
	}
	return (day);
}

int main()
{
	fast;
	int arr[1001][1001];

	cin >> m >> n;
	for (int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> arr[i][j];
		}
	}
	cout << check_tomato(arr);
	return (0);
}
