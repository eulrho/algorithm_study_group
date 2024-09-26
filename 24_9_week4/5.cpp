// 트리 bj.1068
#include <iostream>
#include <vector>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void delete_node(vector<vector<int>> &edges, int target, bool *delete_list)
{
	queue<int> queue;
	int node;

	queue.push(target);
	delete_list[target] = true;
	while (!queue.empty()) {
		node = queue.front();
		queue.pop();
		for (int i=0; i<(int)edges[node].size(); i++) {
			delete_list[edges[node][i]] = true;
			queue.push(edges[node][i]);
		}
	}
}

int main()
{
	fast;
	int n; cin >> n;
	int node, target, cnt=0;
	vector<vector<int>> edges(n);
	bool delete_list[51] = {false,};

	for (int i=0; i<n; i++) {
		cin >> node;
		if (node != -1)
			edges[node].push_back(i);
	}

	cin >> target;
	delete_node(edges, target, delete_list);
	for (int i=0; i<n; i++) {
		if (delete_list[i]) continue ;

		int size = (int)edges[i].size(), tmp = size;
		for (int j=0; j<size; j++) {
			if (delete_list[edges[i][j]])
				tmp--;
		}
		if (tmp == 0) cnt++;
	}
	cout << cnt;
	return (0);
}