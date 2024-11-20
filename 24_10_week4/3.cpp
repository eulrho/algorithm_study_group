// IP Address Summarization (Small) bj.12054
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct trie_node {
	map<char, trie_node*> next;
	bool end_point = false;
};

struct trie {
	trie_node *node;
	trie() {node = new trie_node();};
};

string decimal_to_binary(string &number)
{
	int tmp = stoi(number);
	string res;

	for (int i=0; i<8; i++) {
		res += tmp % 2 + '0';
		tmp /= 2;
	}
	reverse(res.begin(), res.end());
	return res;
}

string binary_to_decimal(string &number)
{
	int res=0;

	for (int i=0; i<8; i++) {
		if (number[i] == '1')
			res += (int)pow(2, 7-i);
	}
	return to_string(res);
}

void convert_d_to_b(string &number, int &subnet)
{
	string res;

	size_t n = number.find('/');
	subnet = stoi(number.substr(n + 1));
	number = number.substr(0, n);

	char separator = '.';
	stringstream ss(number);
	string buf;
	for (int i=0; i<4; i++) {
		getline(ss, buf, separator);
		res += decimal_to_binary(buf);
		if (i != 3) res += separator;
	}
	number = res;
}

void convert_b_to_d(string &number)
{
	string res;

	char separator = '.';
	stringstream ss(number);
	string buf;
	for (int i=0; i<4; i++) {
		getline(ss, buf, separator);
		res += binary_to_decimal(buf);
		if (i != 3) res += separator;
	}
	number = res;
}

void insert(trie_node *parent, string number, int subnet)
{
	int size = subnet + subnet / 8 - (subnet % 8 == 0), idx = 0;

	while (idx < size && parent->next.find(number[idx]) != parent->next.end()) {
		parent = parent->next[number[idx]];
		idx++;
	}
	if (parent->end_point) return ;
	while (idx < size) {
		parent->next[number[idx]] = new trie_node();
		parent = parent->next[number[idx]];
		idx++;
	}
	parent->end_point = true;
}

void fill_address(string &address)
{
	string sample = "00000000.00000000.00000000.00000000";

	address += sample.substr(address.size());
}

void optimize(trie_node *parent) {
	if (parent->end_point) return ;

	map<char, trie_node*>::reverse_iterator iter = parent->next.rbegin();
	for (; iter != parent->next.rend(); iter++) {
		if (!iter->second->end_point) {
			optimize(iter->second);
		}
	}

	if (parent->next.find('.') != parent->next.end() && parent->next['.']->end_point)
		parent->end_point = true;
	if (parent->next.size() == 2 && parent->next['0']->end_point && parent->next['1']->end_point)
		parent->end_point = true;
}

void find_address(trie_node *parent, string address) {
	if (parent->end_point) {
		int tmp=0;
		int size = (int)address.size();

		for (int i=3; i>=1; i--) {
			if (size >= 8 * i + i) {
				tmp = i;
				break ;
			}
		}

		string subnet = "/" + to_string(size - tmp);
		fill_address(address);
		convert_b_to_d(address);
		cout << address + subnet << '\n';
		return ;
	}

	map<char, trie_node*>::iterator iter = parent->next.begin();
	for (; iter != parent->next.end(); iter++) {
		find_address(iter->second, address + iter->first);
	}
}

int main()
{
	fast;
	int t; cin >> t;
	for (int i=1; i<=t; i++) {
		cout << "Case #" << i << ":\n";

		int n; cin >> n;
		trie root;
		string ip;
		int subnet;
		for (int j=0; j<n; j++) {
			cin >> ip;
			convert_d_to_b(ip, subnet);
			insert(root.node, ip, subnet);
		}
		optimize(root.node);
		find_address(root.node, "");
	}
	return 0;
}