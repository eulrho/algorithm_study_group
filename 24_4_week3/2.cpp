// 크로아티아 알파벳 bj.2941
#include <iostream>
#include <string>
using namespace std;
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main()
{
	fast;
	string str;
	int cnt = 0;

	cin >> str;
	for (int i=0; i<str.size(); i++) {
		cnt++;
		if (str[i] == 'c' && i<str.size()-1 && str[i + 1] == '=')
			i++;
		else if (str[i] == 'c' && i<str.size()-1 && str[i + 1] == '-')
			i++;
		else if (str[i] == 'd' && i<str.size()-2 && str[i + 1] == 'z' && str[i + 2] == '=')
			i+=2;
		else if (str[i] == 'd' && i<str.size()-1 && str[i + 1] == '-')
			i++;
		else if (str[i] == 'l' && i<str.size()-1 && str[i + 1] == 'j')
			i++;
		else if (str[i] == 'n' && i<str.size()-1 && str[i + 1] == 'j')
			i++;
		else if (str[i] == 's' && i<str.size()-1 && str[i + 1] == '=')
			i++;
		else if (str[i] == 'z' && i<str.size()-1 && str[i + 1] == '=')
			i++;
	}
	cout << cnt;
	return (0);
}
