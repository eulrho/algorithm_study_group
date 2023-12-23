// 퇴사 2 bj.15486
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define MAX(a, b) (a > b ? a : b);
using namespace std;

int counselling[2][1500002];
int dp[1500002];

int find_max(int n)
{
    int later;

    for (int i=n; i>=1; i--)
    {
        later = counselling[0][i] + i;
        if (later > n + 1) dp[i] = dp[i+1];
        else
            dp[i] = MAX(dp[i+1], counselling[1][i] + dp[later]);
    }
    return (dp[1]);
}

int main()
{
    fast;
    int n;

    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> counselling[0][i] >> counselling[1][i];
    cout << find_max(n);
    return (0);
}