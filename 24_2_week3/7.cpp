// 바이러스 bj.2606
#include <iostream>
#include <vector>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int num_computer, num_edge;
int visited[101] = {0, };

int bfs(vector<vector<int>> edges)
{
	queue<int> queue;
	int node, size, cnt=0;

	queue.push(1);
	visited[1] = 1;
	while(!queue.empty()) {
		node = queue.front();
		if (visited[node] == 0) {
			visited[node] = 1;
			cnt++;
		}
		size = edges[node].size();
		for (int k=0; k<size; k++) {
			if (visited[edges[node][k]] == 0)
				queue.push(edges[node][k]);
		}
		queue.pop();
	}
	return (cnt);
}

int main()
{
	fast;
	int n1, n2;
	cin >> num_computer >> num_edge;

	vector<vector<int>> edges(num_computer + 1);
	for (int i=0; i<num_edge; i++) {
		cin >> n1 >> n2;
		edges[n1].push_back(n2);
		edges[n2].push_back(n1);
	}
	cout << bfs(edges);
	return (0);
}