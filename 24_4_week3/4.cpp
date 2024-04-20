// 수학숙제
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool cmp(string s1, string s2)
{
	if (s1.size() == s2.size()) {
		for (int i=0; i<s1.size(); i++) {
			if (s1[i] != s2[i]) return (s1[i] < s2[i]);
		}
	}
	return (s1.size() < s2.size());
}

int main()
{
	fast;
	int n, idx, start, size;
	string str;
	vector<string> numbers;

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> str;
		size = str.size();
		idx = 0;
		while (idx < size) {
			while (idx < size && (str[idx] >= 'a' && str[idx] <= 'z'))
				idx++;
			if (idx == size) break ;
			while (idx < size && str[idx] == '0') idx++;
			if (str[idx] >= '1' && str[idx] <= '9') {
				start = idx;
				while (idx < size && str[idx] >= '0' && str[idx] <= '9') idx++;
				if (start != idx)
					numbers.push_back(str.substr(start, idx - start));
			}
			else numbers.push_back("0");
		}
	}
	sort(numbers.begin(), numbers.end(), cmp);
	for (int i=0; i<numbers.size(); i++) cout << numbers[i] << '\n';
	return (0);
}
