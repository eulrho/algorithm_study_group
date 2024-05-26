// 앱 bj.7579
#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define MAX(a, b) (a > b ? a : b)
using namespace std;

int dp[101][10001];
int apps[101][2];

int main()
{
	fast;
	int n, M, sum=0;

	cin >> n >> M;
	for (int i=1; i<=n; i++) cin >> apps[i][0];
	for (int i=1; i<=n; i++) {
		cin >> apps[i][1];
		sum += apps[i][1];
	}
	for (int i=1; i<=n; i++) {
		for (int j=0; j<=sum; j++) {
			if (apps[i][1] <= j)
				dp[i][j] = MAX(dp[i-1][j], dp[i-1][j-apps[i][1]] + apps[i][0]);
			dp[i][j] = MAX(dp[i][j], dp[i-1][j]);
		}
	}
	for (int i=0; i<=sum; i++) {
		if (dp[n][i] >= M) {
			cout << i;
			break ;
		}
	}
	return (0);
}
