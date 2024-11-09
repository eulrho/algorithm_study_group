// File Fix-it (Large) bj.12578
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct trie_node {
	map<string, trie_node*> next;
};

struct trie {
	trie_node *node;

	trie() {
		node = new trie_node();
	}
};

int insert(string path, trie_node *parent)
{
	int cnt=0;
	char separator = '/';
	stringstream ss(path);
	string buff;

	while (getline(ss, buff, separator)) {
		if (buff.empty()) continue ;

		if (parent->next.find(buff) == parent->next.end()) {
			cnt++;
			parent->next[buff] = new trie_node();
		}
		parent = parent->next[buff];
	}
	return cnt;
}

int main()
{
	fast;
	int t, n, m;

	cin >> t;
	for (int i=1; i<=t; i++) {
		string path;
		trie root;
		int res = 0;

		cin >> n >> m;

		for (int j=0; j<n; j++) {
			cin >> path;
			insert(path, root.node);
		}
		for (int j=0; j<m; j++) {
			cin >> path;
			res += insert(path, root.node);
		}

		cout << "Case #" << i << ": " << res << '\n';
	}
	return 0;
}