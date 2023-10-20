// IOIOI bj.5525
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int N, S, cnt = 0, res = 0;
    char M, before = 'O';
    bool start = false;

    cin >> N >> S;
    for (int i=0; i<S; i++)
    {
        cin >> M;
        if (start == false && (before == 'I' && M == 'O'))
            start = true;
        if (start == true && (before == 'O' && M == 'I'))
            cnt++;
        if ((before == 'O' && M == 'O') || (before == 'I' && M == 'I'))
        {
            if (cnt >= N)
                res += cnt - (N - 1);
            start = false;
            cnt = 0;
        }
        before = M;
    }
    if (before != 'O' && cnt >= N)
        res += cnt - (N - 1);
    cout << res;
    return (0);
}
