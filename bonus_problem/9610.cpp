// 사분면
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

using namespace std;
int main()
{
    fast;
    int n, x, y, ans[5] = {0,};

    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> x >> y;
        if (x == 0 || y == 0)
            ans[4]++;
        else if (x < 0)
            y < 0 ? ans[2]++ : ans[1]++;
        else
            y < 0 ? ans[3]++ : ans[0]++;
    }
    for (int i=0; i<5; i++)
    {
        if (i == 4)
            cout << "AXIS: " << ans[i] << '\n';
        else
            cout << 'Q' << i + 1 << ": " << ans[i] << '\n';
    }
    return (0);
}