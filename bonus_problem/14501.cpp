// 퇴사
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define MAX(a, b) (a > b ? a : b);
using namespace std;

int counselling[2][20];
int dp[20];

int find_max(int n)
{
	for (int i=n-1; i>=0; i--) {
		if (counselling[0][i] + i > n)
			dp[i] = dp[i+1];
		else
			dp[i] = MAX(dp[i+1], dp[counselling[0][i] + i]+counselling[1][i]);
	}
	return (dp[0]);
}

int main()
{
	fast;
	int n, t, p;

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> t >> p;
		counselling[0][i] = t;
		counselling[1][i] = p;
	}
	cout << find_max(n);
	return (0);
}