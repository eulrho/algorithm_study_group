// 스티커 bj.9465
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int sticker[2][100000];

int max_score(int n)
{
    int max;

    if (n == 1)
        max = sticker[0][0] > sticker[1][0] ? sticker[0][0] : sticker[1][0];
    else if (n == 2)
        max = sticker[0][0] + sticker[1][1] > sticker[0][1] + sticker[1][0] ? sticker[0][0] + sticker[1][1] : sticker[0][1] + sticker[1][0];
    else {
        for (int j=1; j<n; j++) {
            for (int i=0; i<2; i++) {
                if (i == 0)
                {
                    if (j == 1)
                        sticker[i][j] += sticker[i + 1][j - 1];
                    else if (sticker[i + 1][j - 1] > sticker[i + 1][j - 2]) {
                        sticker[i][j] += sticker[i + 1][j - 1];
                    }
                    else
                        sticker[i][j] += sticker[i + 1][j - 2];
                }
                else
                {
                    if (j == 1)
                        sticker[i][j] += sticker[i - 1][j - 1];
                    else if (sticker[i - 1][j - 1] > sticker[i - 1][j - 2]) {
                        sticker[i][j] += sticker[i - 1][j - 1];
                    }
                    else
                        sticker[i][j] += sticker[i - 1][j - 2];
                }
            }
        }
        max = sticker[0][n-1] > sticker[1][n-1] ? sticker[0][n-1] : sticker[1][n-1];
    }
    return (max);
}

int main()
{
    fast;
    int t, n;

    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        for (int j=0; j<2; j++) {
            for (int k=0; k<n; k++)
                cin >> sticker[j][k];
        }
        cout << max_score(n) << '\n';
    }
    return (0);
}