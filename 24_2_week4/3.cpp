// 캡틴 이다솜 bj.1660
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

#define min(x, y) (x > y ? y : x)

int main()
{
	fast;
	int n; cin >> n;
	int dp[n+1];
	int a, b, c;

	a = b = c = 1;
	for(int i=0; i<=n; i++)
		dp[i] = i;
	while (c <= n) {
		for (int k=1; k<=n; k++) {
			if (k >= c)
				dp[k] = min(dp[k], dp[k-c]+1);
		}
		a += 1;
		b += a;
		c += b;
	}
	cout << dp[n];
	return (0);
}