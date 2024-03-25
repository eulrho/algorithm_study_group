// 트리 순회 bj.1991
#include <iostream>
#include <vector>
#include <utility>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void postorder(vector<pair<char, char>> tree, int idx)
{
	if (tree[idx].first != '.')
		postorder(tree, tree[idx].first - 'A');
	if (tree[idx].second != '.')
		postorder(tree, tree[idx].second - 'A');
	cout << (char)(idx + 'A');
}

void inorder(vector<pair<char, char>> tree, int idx)
{
	if (tree[idx].first != '.')
		inorder(tree, tree[idx].first - 'A');
	cout << (char)(idx + 'A');
	if (tree[idx].second != '.')
		inorder(tree, tree[idx].second - 'A');
}

void preorder(vector<pair<char, char>> tree, int idx)
{
	cout << (char)(idx + 'A');
	if (tree[idx].first != '.')
		preorder(tree, tree[idx].first - 'A');
	if (tree[idx].second != '.')
		preorder(tree, tree[idx].second - 'A');
}

int main()
{
	fast;
	int n; cin >> n;
	vector<pair<char, char>> tree(n);
	char node, left, right;

	for (int i=0; i<n; i++) {
		cin >> node >> left >> right;
		tree[node - 'A'] = make_pair(left, right);
	}
	preorder(tree, 0);
	cout << '\n';
	inorder(tree, 0);
	cout << '\n';
	postorder(tree, 0);
	return (0);
}