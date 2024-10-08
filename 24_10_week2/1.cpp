// 특정 거리의 도시 찾기 bj.18352
#include <iostream>
#include <vector>
#include <queue>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void find_min_distance(vector<vector<int> > &edges, int *arr, int start, int n)
{
	int visited[n+1];
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	for (int i=0; i<=n; i++) {
		arr[i] = n + 2;
		visited[i] = 0;
	}
	arr[start] = 0;
	pq.push(make_pair(0, start));

	int value;
	while (!pq.empty()) {
		start = pq.top().second;
		value = pq.top().first;
		pq.pop();
		if (visited[start]) continue ;
		visited[start] = 1;
		for (int i=0; i<(int)edges[start].size(); i++) {
			if (arr[edges[start][i]] > arr[start] + 1) {
				arr[edges[start][i]] = arr[start] + 1;
				pq.push(make_pair(arr[edges[start][i]], edges[start][i]));
			}
		}
	}
}

int main()
{
	fast;
	int n, m, k, x;
	cin >> n >> m >> k >> x;

	vector<vector<int> > edges(n+1);
	int a, b;
	for (int i=0; i<m; i++) {
		cin >> a >> b;
		edges[a].push_back(b);
	}

	int arr[n+1];
	find_min_distance(edges, arr, x, n);

	int flag = false;
	for (int i=1; i<=n; i++) {
		if (arr[i] == k) {
			flag = true;
			cout << i << '\n';
		}
	}
	if (!flag) cout << -1;
	return 0;
}