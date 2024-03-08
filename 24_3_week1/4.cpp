// 퇴사 2
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int arr[1500001][2];
int dp[1500001];

void counseling(int n)
{
	for (int i=n-1; i>=0; i--) {
		if (n - i < arr[i][0]) dp[i] = dp[i+1];
		else dp[i] = dp[i+arr[i][0]] + arr[i][1] < dp[i+1] ? dp[i+1] : dp[i+arr[i][0]] + arr[i][1];
	}
}

int main()
{
	fast;
	int n;

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> arr[i][0] >> arr[i][1];
	counseling(n);
	cout << dp[0];
	return (0);
}
