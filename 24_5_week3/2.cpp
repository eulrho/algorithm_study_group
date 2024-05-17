// 신나는 함수 실행 bj.9184
#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int dp[52][52][52];
int cnt;

int w(int a, int b, int c)
{
	if (dp[a][b][c] != -1) return (dp[a][b][c]);
	if (a <= 0 || b <= 0 || c <= 0) dp[a][b][c] = 1;
	else if (a > 20 || b > 20 || c > 20) dp[a][b][c] = w(20, 20, 20);
	else if (a < b && b < c) dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
	else dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
	return (dp[a][b][c]);
}

int main()
{
	fast;
	int a, b, c;

	while (true) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break ;

		cout << "w(" << a << ", " << b << ", " << c << ") = ";
		if (a <= 0 || b <= 0 || c <= 0) {
			cout << "1\n";
			continue ;
		}
		fill(&dp[0][0][0], &dp[51][51][51], -1);
		cout << w(a, b, c) << '\n';
	}
	return (0);
}
