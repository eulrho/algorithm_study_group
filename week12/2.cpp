// 파도반 수열 bj.9461
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

long long seq[101];

long long padovan(int n)
{
    seq[1] = 1;
    seq[2] = 1;
    seq[3] = 1;
    for (int i=4; i<=n; i++)
        seq[i] = seq[i-3] + seq[i-2];
    return (seq[n]);
}

int main()
{
    fast;
    int t, n;

    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> n;
        cout << padovan(n) << '\n';
    }
    return (0);
}