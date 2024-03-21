// 안전 영역 bj.2468
#include <iostream>
#include <queue>
#include <utility>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void find_ground(int visited[][101], int arr[][101], int target, int n, int origin_y, int origin_x)
{
	queue<pair<int, int>> queue;
	int y, x;
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, -1, 0, 1};

	queue.emplace(origin_y, origin_x);
	while (!queue.empty()) {
		y = queue.front().first;
		x = queue.front().second;
		queue.pop();
		for (int k=0; k<4; k++) {
			if (y + dy[k] < 0 || y + dy[k] >= n || x + dx[k] < 0 || x + dx[k] >= n)
				continue ;
			if (visited[y + dy[k]][x + dx[k]] == 0 && arr[y + dy[k]][x + dx[k]] <= target) {
				visited[y + dy[k]][x + dx[k]] = 1;
				queue.emplace(y+dy[k], x+dx[k]);
			}
		}
	}
}

int check_area(int n, int arr[][101], int max, int min)
{
	int res = 1;
	int cnt;

	for (int i=min; i<=max; i++) {
		int visited[101][101] = {0, };

		cnt = 0;
		for (int j=0; j<n; j++) {
			for (int k=0; k<n; k++) {
				if (visited[j][k] == 0 && arr[j][k] <= i) {
					visited[j][k] = 1;
					find_ground(visited, arr, i, n, j, k);
				}
			}
		}
		for (int j=0; j<n; j++) {
			for (int k=0; k<n; k++) {
				if (visited[j][k] == 0) {
					visited[j][k] = 1;
					cnt++;
					find_ground(visited, arr, max, n, j, k);
				}
			}
		}
		res = res < cnt ? cnt : res;
	}
	return (res);
}

int main()
{
	fast;
	int n, arr[101][101], max=0, min=100;

	cin >> n;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> arr[i][j];
			max = max < arr[i][j] ? arr[i][j] : max;
			min = min < arr[i][j] ? min : arr[i][j];
		}
	}
	cout << check_area(n, arr, max, min);
	return (0);
}
