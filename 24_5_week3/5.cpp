// 동전 bj.9084
#include <iostream>
#include <cstring>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int t, n, m;

	cin >> t;
	for (int i=0; i<t; i++) {
		cin >> n; int coins[n];
		for (int j=0; j<n; j++) cin >> coins[j];
		cin >> m; int money[m + 1];
		memset(money, 0, sizeof(int)*(m+1));
		money[0] = 1;
		for (int j=0; j<n; j++) {
			for (int k=1; k<=m; k++) {
				if (coins[j] > k) continue ;
				money[k] += money[k-coins[j]];
			}
		}
		cout << money[m] << '\n';
	}
	return (0);
}
