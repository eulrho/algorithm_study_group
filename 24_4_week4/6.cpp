// 평범한 배낭 bj.12865
#include <iostream>
#include <vector>
#include <utility>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define MAX(a, b) (a < b ? b : a)
using namespace std;

int max_value[101][200001];

int main()
{
	fast;
	int n, k, w, v;
	vector<pair<int, int>> bag;

	cin >> n >> k;
	bag.emplace_back(0, 0);
	for (int i=0; i<n; i++) {
		cin >> w >> v;
		bag.emplace_back(w, v);
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=k; j++) {
			if (bag[i].first > j)
				max_value[i][j] = max_value[i - 1][j];
			else
				max_value[i][j] = MAX(max_value[i - 1][j], max_value[i - 1][j - bag[i].first] + bag[i].second);
		}
	}
	cout << max_value[n][k];
	return (0);
}
