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
	int x, n;
	vector<int> positions;
	vector<int> temp;
	map<int, int> samples;

	cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> x;
		positions.push_back(x);
	}
	temp = positions;
	sort(temp.begin(), temp.end());
	temp.erase(unique(temp.begin(), temp.end()), temp.end());
	for (int i=0; i<temp.size(); i++)
		samples.insert({temp[i], i});
	for (int i=0; i<n; i++)
		cout << samples[positions[i]] << ' ';
	return (0);
}