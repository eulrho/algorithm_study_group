// 안녕 bj.1535
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int max_p;

void find_max_reward(int n, int i, int sum_hp, int sum_re, vector<pair<int, int>> humans)
{
	if (i == n-1 || sum_hp >= 100) {
		max_p = max_p < sum_re ? sum_re : max_p;
		return ;
	}
	for (int k=i+1; k<n; k++) {
		if (humans[k].first + sum_hp >= 100) {
			find_max_reward(n, k, sum_hp + humans[k].first, sum_re, humans);
			break ;
		}
		else
			find_max_reward(n, k, sum_hp + humans[k].first, sum_re + humans[k].second, humans);

	}
}

int main()
{
	fast;
	int n, hp, reward;
	vector<pair<int, int>> humans;

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> hp;
		humans.emplace_back(hp, 0);
	}
	for (int i=0; i<n; i++) {
		cin >> reward;
		humans[i].second = reward;
	}
	sort(humans.begin(), humans.end());
	find_max_reward(n, -1, 0, 0, humans);
	cout << max_p;
	return (0);
}