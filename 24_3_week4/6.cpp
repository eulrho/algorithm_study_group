// 스티커 bj.9465
#include <iostream>
#include <cstring>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define MAX(a, b) (a > b ? a : b)
using namespace std;

int dp[2][100000];
int arr[2][100000];

void initial_array()
{
	for (int i=0; i<2; i++) {
		memset(dp[i], 0, sizeof(dp[i]));
		memset(arr[i], 0, sizeof(arr[i]));
	}
}

int find_max_score(int n)
{
	int temp;

	dp[0][0] = arr[0][0];
	dp[1][0] = arr[1][0];
	for (int i=1; i<n; i++) {
		if (dp[0][i] == 0) dp[0][i] = arr[0][i];
		temp = MAX(dp[0][i], dp[1][i - 1] + dp[0][i]);
		if (i - 2 >= 0) {
			temp = MAX(temp, dp[1][i - 2] + dp[0][i]);
			temp = MAX(temp, dp[0][i - 2] + dp[0][i]);
		}
		dp[0][i] = temp;
		if (dp[1][i] == 0) dp[1][i] = arr[1][i];
		temp = MAX(dp[1][i], dp[0][i - 1] + dp[1][i]);
		if (i - 2 >= 0) {
			temp = MAX(temp, dp[1][i - 2] + dp[1][i]);
			temp = MAX(temp, dp[0][i - 2] + dp[1][i]);
		}
		dp[1][i] = temp;
	}
	return (MAX(dp[0][n-1], dp[1][n-1]));
}

int main()
{
	fast;
	int t, n;

	cin >> t;
	for (int i=0; i<t; i++) {
		cin >> n;
		initial_array();

		for (int j=0; j<2; j++) {
			for (int k=0; k<n; k++) cin >> arr[j][k];
		}
		cout << find_max_score(n) << '\n';
	}
	return (0);
}