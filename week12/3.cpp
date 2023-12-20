// 쉬운 계단 수 bj.10844
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

unsigned long long stair(int n)
{
    unsigned long long dp[101][10];
    unsigned long long count = 0;

    dp[1][0] = 0;
    for (int i=1; i<=9; i++)
        dp[1][i] = 1;
    for (int i=2; i<=n; i++) {
        for (int j=0; j<=9; j++) {
            if (j == 0)
                dp[i][0] = dp[i-1][1];
            else if (j == 9)
                dp[i][9] = dp[i-1][8];
            else
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
            if (dp[i][j] >= 1000000000)
                dp[i][j] %= 1000000000;
        }
    }
    for (int i=0; i<=9; i++) {
        count += dp[n][i];
        if (count >= 1000000000)
            count %= 1000000000;
    }
    return (count);
}

int main()
{
    fast;
    int n;

    cin >> n;
    cout << stair(n) << '\n';
    return (0);
}