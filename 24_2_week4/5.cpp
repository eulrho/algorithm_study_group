// ROT13 bj.11655
#include <iostream>
#include <string>
#include <cctype>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void encryption(string &str)
{
	int size = (int)str.size();

	for (int i=0; i<size; i++) {
		if (isalpha(str[i]) == 0) continue ;
		else if (str[i] >= 'a' && str[i] <= 'z' && str[i] + 13 > 'z')
			str[i] = str[i] + 13 - 'z' - 1 + 'a';
		else if (str[i] >= 'A' && str[i] <= 'Z' && str[i] + 13 > 'Z')
			str[i] = (char)str[i] + 13 - 'Z' - 1 + 'A';
		else str[i] = (char)str[i] + 13;
	}
}

int main()
{
	fast;
	string str;

	getline(cin, str);
	encryption(str);
	cout << str;
	return (0);
}