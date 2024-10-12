// 최소비용 구하기 bj.1916
#include <iostream>
#include <vector>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int find_min_cost(vector<vector<pair<int, int>>> &bus, int start, int dest, int n)
{
	int arr[n+1], visited[n+1];
	for (int i=0; i<n+1; i++) {
		arr[i] = -1;
		visited[i] = 0;
	}
	arr[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, start});
	while (!pq.empty()) {
		start = pq.top().second;
		pq.pop();
		if (visited[start] == 1) continue ;
		visited[start] = 1;
		for (int i=0; i<(int)bus[start].size(); i++) {
			int city = bus[start][i].first;
			int cost = bus[start][i].second;
			if (arr[city] == -1 || arr[city] > arr[start] + cost) {
				arr[city] = arr[start] + cost;
				pq.push({arr[city], city});
			}
		}
	}
	return arr[dest];
}

int main()
{
	fast;
	int n, m, start, dest;
	cin >> n >> m;

	vector<vector<pair<int, int>>> bus(n + 1);
	int a, b, cost;
	for (int i=0; i<m; i++) {
		cin >> a >> b >> cost;
		bus[a].emplace_back(b, cost);
	}

	cin >> start >> dest;
	cout << find_min_cost(bus, start, dest, n);
	return (0);
}