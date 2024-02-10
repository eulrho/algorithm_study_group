// 단어 뒤집기 2 bj.17413
#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	string s;
	int len, is_tag = 0, start, idx = 0;

	getline(cin, s);
	len = s.size();
	while (idx < len) {
		if (s[idx] == '<') is_tag = 1;
		while (s[idx] == ' ' || is_tag) {
			cout << s[idx];
			if (s[idx] == '>') is_tag = 0;
			idx++;
		}
		if (idx >= len)
			break ;
		start = idx;
		while (idx < len && s[idx] != '<' && s[idx] != ' ')
			idx++;
		for (int i=idx-1; i>=start; i--)
			cout << s[i];
	}
	return (0);
}