// Strfry bj.11328
#include <iostream>
#include <string>
#include <cstring>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

string is_possible(string str1, string str2)
{
	bool check[1001];
	int s1_size=(int)str1.size(), s2_size=(int)str2.size();

	if (s1_size != s2_size) return ("Impossible");
	memset(check, false, sizeof(bool)*s1_size);
	for (int j=0; j<s2_size; j++) {
		for (int k=0; k<s1_size; k++) {
			if (str2[j] == str1[k]) {
				if (check[k] == false) {
					check[k] = true;
					break ;
				}
			}
		}
	}
	for (int i=0; i<s1_size; i++) {
		if (check[i] == false) return ("Impossible");
	}
	return ("Possible");
}

int main()
{
	fast;
	int n;
	string str1, str2;

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> str1 >> str2;
		cout << is_possible(str1, str2) << '\n';
	}
	return (0);
}

