// LCS bj.9251
#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define MAX(a, b) (a > b ? a : b)
using namespace std;

int lcs[1001][1001];

void find_lcs(string str1, string str2)
{
	int s1_size = str1.size(), s2_size = str2.size();

	for (int i=1; i<s1_size; i++) {
		for (int j=1; j<s2_size; j++) {
			if (str1[i] == str2[j])
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else lcs[i][j] = MAX(lcs[i][j - 1], lcs[i - 1][j]);
		}
	}
	cout << lcs[s1_size - 1][s2_size - 1];
}

int main()
{
	fast;
	string str1, str2;

	cin >> str1 >> str2;
	str1 = '_' + str1;
	str2 = '_' + str2;
	find_lcs(str1, str2);
	return (0);
}