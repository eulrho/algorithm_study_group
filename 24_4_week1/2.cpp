// 접미사 배열 bj.11656
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int size;
	string str;
	vector<string> v;

	cin >> str;
	size = (int)str.size();
	for (int i=0; i<size; i++)
		v.push_back(str.substr(i, size-i));
	sort(v.begin(), v.end());
	for (int i=0; i<size; i++)
		cout << v[i] << '\n';
	return (0);
}