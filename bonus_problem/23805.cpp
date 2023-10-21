// 골뱅이 찍기 - 돌아간 ㄹ
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

using namespace std;
int main()
{
    fast;
    int N, max;
    bool check;

    cin >> N;
    max = 5*N;
    for (int i=1; i<=max; i++)
    {
        for (int j=1; j<=max; j++)
        {
            if ((j > 3 * N && j <= max - N) || (j > N && j <= N * 2))
            {
                if (i <= N && (j > N && j <= N * 2))
                    check = true;
                else if (i >= max - (N - 1) && (j > 3 * N && j <= max - N))
                    check = true;
                else
                    check = false;
            }
            else
                check = true;
            if (check == true)
                cout << '@';
            else
                cout << ' ';
        }
        cout << '\n';
    }
    return (0);
}