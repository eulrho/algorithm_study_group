// 서로 다른 부분 문자열의 개수 bj.11478
#include <iostream>
#include <string>
#include <map>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int size;
	string str;
	map<string, int> res;

	cin >> str;
	size = (int)str.size();
	for (int i=0; i<size; i++) {
		for (int j=1; j<=size-i; j++)
			res.insert({str.substr(i, j), 0});
	}
	cout << res.size();
	return (0);
}