// 최단경로 bj.1753
#include <iostream>
#include <vector>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, e, k;
	cin >> n >> e >> k;

	vector<vector<pair<int, int> > > edge(n+1);
	int u, v, w;
	for (int i=0; i<e; i++) {
		cin >> u >> v >> w;
		edge[u].push_back(make_pair(v, w));
	}

	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	bool visited[n+1];
	int arr[n+1], start;
	for (int i=0; i<=n; i++) {
		visited[i] = false;
		arr[i] = -1;
	}
	arr[k] = 0;
	pq.push(make_pair(0, k));
	while (!pq.empty()) {
		start = pq.top().second;
		pq.pop();
		if (visited[start]) continue;
		visited[start] = true;

		for (int i=0; i<(int)edge[start].size(); i++) {
			int target = edge[start][i].first;
			int value = edge[start][i].second;

			if (arr[target] == -1 || arr[target] > arr[start] + value) {
				arr[target] = arr[start] + value;
				pq.push(make_pair(arr[target], target));
			}
		}
	}

	for (int i=1; i<=n; i++) {
		if (arr[i] == -1) cout << "INF\n";
		else cout << arr[i] << '\n';
	}
	return 0;
}