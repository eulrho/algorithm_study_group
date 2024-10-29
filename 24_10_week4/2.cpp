// 개미굴 bj.14725
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct trie_node {
	map<string, trie_node*> child;
};

struct trie {
	trie_node *node;

	trie() {this->node = new trie_node();}
};

void insert(trie_node **parent, string data) {
	if ((*parent)->child.find(data) == (*parent)->child.end())
		(*parent)->child[data] = new trie_node();
	*parent = (*parent)->child[data];
}

void print(trie_node *parent, int depth)
{
	if (parent->child.empty()) return ;

	map<string, trie_node*>::iterator iter = parent->child.begin();
	string dash;
	dash.append(depth * 2, '-');
	for (;iter!=parent->child.end(); iter++) {
		cout << dash << iter->first << '\n';
		print(iter->second, depth + 1);
	}

}

int main()
{
	fast;
	int n; cin >> n;

	trie root;
	int k;
	for (int i=0; i<n; i++) {
		cin >> k;

		trie_node *tmp = root.node;
		string str;
		for (int j=0; j<k; j++) {
			cin >> str;
			insert(&tmp, str);
		}
	}
	print(root.node, 0);
	return 0;
}