// 비밀번호 찾기 bj.17219
#include <iostream>
#include <string>
#include <unordered_map>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, m;
	string address, password;
	unordered_map<string, string> websites;

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> address >> password;
		websites.insert(make_pair(address, password));
	}
	for (int i=0; i<m; i++) {
		cin >> address;
		cout << websites[address] << '\n';
	}
	return (0);
}