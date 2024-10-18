// 녹색 옷 입은 애가 젤다지? bj.4485
#include <iostream>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int find_min_cost(int arr[][126], int n)
{
	priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
	bool visited[126][126]={false};
	int cost[n][n];
	int y, x;
	int dy[4] = {0, -1, 0, 1};
	int dx[4] = {-1, 0, 1, 0};

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) cost[i][j] = -1;
	}
	pq.push(make_pair(arr[0][0], make_pair(0, 0)));
	cost[0][0] = arr[0][0];
	while (!pq.empty()) {
		y = pq.top().second.first;
		x = pq.top().second.second;
		pq.pop();

		if (visited[y][x]) continue ;
		visited[y][x] = true;

		for (int i=0; i<4; i++) {
			int new_y = y + dy[i];
			int new_x = x + dx[i];
			if (new_y < 0 || new_y >= n || new_x < 0 || new_x >= n) continue ;
			if (cost[new_y][new_x] == -1 || cost[new_y][new_x] > arr[new_y][new_x] + cost[y][x]) {
				cost[new_y][new_x] = arr[new_y][new_x] + cost[y][x];
				pq.push(make_pair(cost[new_y][new_x], make_pair(new_y, new_x)));
			}
		}
	}
	return cost[n-1][n-1];
}

int main()
{
	fast;
	int n, seq=1;

	while (true) {
		cin >> n;
		if (n == 0) break ;

		int arr[126][126];
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) cin >> arr[i][j];
		}
		cout << "Problem " << seq << ": " << find_min_cost(arr, n) << '\n';
		seq++;
	}
	return 0;
}