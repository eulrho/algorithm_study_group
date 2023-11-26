// Moo 게임 bj.5904
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

string s0 = "moo";
// len <- 이전 단계 길이
void recursive(int n, int k, int len)
{
    int new_len = 2*(len) + k+3; // <- 현재 길이

    if (n <= 3) {
        cout << s0[n-1];
        return ;
    }
    if (new_len < n) recursive(n, k+1, new_len);
    else {
        if (len + 1 <= n && len + k + 3 >= n) {
            if (n == len + 1) cout << 'm';
            else cout << 'o';
        }
        else recursive(n-len-k-3, 1, 3);
    }
}

int main()
{
    fast;
    int n;

    cin >> n;
    recursive(n, 1, 3);
    return (0);
}