// 1, 2, 3 더하기 bj.9095
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int dp[12];

void set_arr()
{
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i=4; i<=11; i++)
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
}

int main()
{
	fast;
	int t, n;

	cin >> t;
	set_arr();
	for (int i=0; i<t; i++) {
		cin >> n;
		cout << dp[n] << '\n';
	}
	return (0);
}