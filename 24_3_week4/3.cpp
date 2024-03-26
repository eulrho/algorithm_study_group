// 트리 bj.10068
#include <iostream>
#include <vector>
#include <stack>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void delete_node(vector<vector<int>> tree, int cnt_nodes[], int n, int del_node)
{
	stack<int> st;
	int visited[51]={0, }, node, flag;

	st.push(del_node);
	visited[del_node] = 1;
	while (!st.empty()) {
		node = st.top();
		cnt_nodes[node] = -1;
		flag = 0;
		for (int i=0; i<tree[node].size(); i++) {
			if (visited[tree[node][i]] == 0) {
				visited[tree[node][i]] = 1;
				st.push(tree[node][i]);
				flag = 1;
				break ;
			}
		}
		if (flag == 0) st.pop();
	}
}

int main()
{
	fast;
	int n, node, res=0; cin >> n;
	vector<vector<int>> tree(n);
	int parents[51], cnt_nodes[51]={0,};

	for (int i=0; i<n; i++) {
		cin >> parents[i];
		if (parents[i] != -1) {
			tree[parents[i]].push_back(i);
			cnt_nodes[parents[i]]++;
		}
	}
	cin >> node;
	cnt_nodes[parents[node]]--;
	delete_node(tree, cnt_nodes, n, node);
	for (int i=0; i<n; i++) {
		if (cnt_nodes[i] == 0) res++;
	}
	cout << res;
	return (0);
}