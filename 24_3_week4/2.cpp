// 트리의 부모 찾기 bj.11725
#include <iostream>
#include <vector>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int visited[100001];

void find_parent(vector<int> &parent, vector<vector<int>> tree, int n)
{
	queue<int> queue;
	int node;

	visited[1] = 1;
	queue.push(1);
	while (!queue.empty()) {
		node = queue.front();
		queue.pop();
		for (int i=0; i<tree[node].size(); i++) {
			if (visited[tree[node][i]] == 0) {
				visited[tree[node][i]] = 1;
				parent[tree[node][i]] = node;
				queue.push(tree[node][i]);
			}
		}
	}
}

int main()
{
	fast;
	int n, a, b; cin >> n;
	vector<vector<int>> tree (n+1);
	vector<int> parent(n+1);

	for (int i=0; i<n-1; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	find_parent(parent, tree, n);
	for (int i=2; i<=n; i++) cout << parent[i] << '\n';
	return (0);
}