// 쉬운 계단 수 bj.10844
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int step(int n)
{
	int dp[101][10], count=0;

	dp[1][0] = 0;
	for (int i=1; i<10; i++)
		dp[1][i] = 1;
	for (int i=2; i<=n; i++) {
		for (int j=0; j<=9; j++) {
			if (j == 0) dp[i][j] = dp[i-1][1] % 1000000000;
			else if (j == 9) dp[i][j] = dp[i-1][j-1] % 1000000000;
			else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
		}
	}
	for (int i=0; i<=9; i++)
		count = (count + dp[n][i]) % 1000000000;
	return (count);
}

int main()
{
	fast;
	int n;

	cin >> n;
	if (n == 1) cout << 9;
	else if (n == 2) cout << 17;
	else cout << step(n);
	return (0);
}