// 좌표 압축 bj.18870
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, number; cin >> n;
	map<int, int> numbers;
	vector<int> sequence;

	for (int i=0; i<n; i++)
	{
		cin >> number;
		numbers.insert({number, 0});
		sequence.push_back(number);
	}
	vector<pair<int, int>> tmp = vector<pair<int, int>>(numbers.begin(), numbers.end());
	sort(tmp.begin(), tmp.end());

	int idx = 0, size = (int)tmp.size();
	while (idx < size) {
		int target = tmp[idx].first;

		numbers[target] = idx;
		while (idx < size && target == tmp[idx].first) idx++;
	}

	for (int i=0; i<(int)sequence.size(); i++)
		cout << numbers[sequence[i]] << ' ';
	return (0);
}