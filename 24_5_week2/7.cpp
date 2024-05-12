// 여행 가자 bj.1976
#include <iostream>
#include <vector>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int route[1001];

bool check_route(int start, int end, vector<vector<int>> cities)
{
	queue<int> queue;
	int city;
	bool visited[201] = {false, };

	visited[start] = true;
	queue.push(start);
	while (!queue.empty()) {
		city = queue.front();
		if (city == end)
			return (true);
		for (int i=0; i<(int)cities[city].size(); i++) {
			if (!visited[cities[city][i]]) {
				visited[cities[city][i]] = true;
				queue.push(cities[city][i]);
			}
		}
		queue.pop();
	}
	return (false);
}

int main()
{
	fast;
	int n, m, is_linked; cin >> n;
	vector<vector<int>> cities(n + 1);

	cin >> m;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			cin >> is_linked;
			if (is_linked) cities[i].push_back(j);
		}
	}
	for (int i=0; i<m; i++) cin >> route[i];
	if (m <= 1) {
		cout << "NO";
		return (0);
	}
	for (int i=0; i<m-1; i++) {
		if (!check_route(route[i], route[i+1], cities)) {
			cout << "NO";
			return (0);
		}
	}
	cout << "YES";
	return (0);
}