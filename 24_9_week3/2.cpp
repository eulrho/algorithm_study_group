// 1, 2, 3 더하기 bj.9095
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void fill_dp(int *dp)
{
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i=4; i<11; i++)
		dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
}

int main()
{
	fast;
	int t, n, dp[11] = {0,};

	cin >> t;
	fill_dp(dp);
	for (int i=0; i<t; i++) {
		cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}