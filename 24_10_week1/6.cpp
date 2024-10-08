// 퇴사 2 bj.15486
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n; cin >> n;
	int arr[n][2], dp[n + 1];
	for (int i=0; i<n; i++)
		cin >> arr[i][0] >> arr[i][1];
	for (int i=0; i<=n; i++) dp[i] = 0;
	for (int i=n-1; i>=0; i--) {
		if (i + arr[i][0] > n) dp[i] = dp[i+1];
		else dp[i] = max(dp[i+1], dp[i + arr[i][0]] + arr[i][1]);
	}
	cout << dp[0];
	return 0;
}
