// 동물원 bj.1309
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int dp[100001];

int main()
{
	fast;
	int n;

	cin >> n;
	dp[1] = 3;
	dp[2] = 7;
	for (int i=3; i<=n; i++)
		dp[i] = (dp[i - 1] + (dp[i - 1] + dp[i - 2]) % 9901) % 9901;
	cout << dp[n];
	return (0);
}
