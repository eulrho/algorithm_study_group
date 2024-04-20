// 단어 정렬 bj.1181
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool cmp(string a, string b)
{
	int idx = 0;
	int a_size = (int)a.size(), b_size = (int)b.size();

	if (a_size != b_size) return (a_size < b_size);
	while (idx < a_size && a[idx] == b[idx]) idx++;
	return (a[idx] < b[idx]);
}

int main()
{
	fast;
	string word;
	vector<string> words;
	int n;

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> word;
		words.push_back(word);
	}
	sort(words.begin(), words.end(), cmp);
	words.erase(unique(words.begin(), words.end()), words.end());
	for (auto w : words) cout << w << '\n';
	return (0);
}