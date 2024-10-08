// 평범한 배낭 bj.12865
#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, k, w, v; cin >> n >> k;

	int bag[k+1][n+1];
	for (int i=0; i<=k; i++) {
		for (int j=0; j<=n; j++)
			bag[i][j] = 0;
	}
	vector<pair<int, int> > value(n+1);
	for (int i=1; i<=n; i++) {
		cin >> w >> v;
		value[i] = make_pair(w, v);
	}
	sort(value.begin(), value.end());
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=k; j++) {
			if (value[i].first > j)
				bag[j][i] = bag[j][i-1];
			else
				bag[j][i] = max(bag[j][i-1], bag[j-value[i].first][i-1] + value[i].second);
		}
	}
	cout << bag[k][n];
	return 0;
}