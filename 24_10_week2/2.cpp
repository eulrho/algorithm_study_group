// 여행 가자 bj.1976
#include <iostream>
#include <vector>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool bfs(int start, int end, vector<vector<int> > city, int n)
{
	int visited[n+1];
	for (int i=1; i<=n; i++) visited[i] = 0;
	visited[start] = 1;

	queue<int> queue;
	int pos;
	queue.push(start);
	while (!queue.empty()) {
		pos = queue.front();
		if (pos == end) return true;
		queue.pop();
		for (int i=0; i<(int)city[pos].size(); i++) {
			if (visited[city[pos][i]] == 0) {
				visited[city[pos][i]] = 1;
				queue.push(city[pos][i]);
			}
		}
	}
	return false;
}

int main()
{
	fast;
	int n, m;
	cin >> n >> m;

	vector<vector<int> > city(n+1);
	int a;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			cin >> a;
			if (a == 1) city[i].push_back(j);
		}
	}

	int start, end;
	bool flag = true;
	for (int j=0; j<m; j++) {
		if (j == 0) cin >> start;
		else {
			cin >> end;
			if (!bfs(start, end, city, n))
				flag = false;
			start = end;
		}
	}
	if (!flag) cout << "NO";
	else cout << "YES";
	return 0;
}