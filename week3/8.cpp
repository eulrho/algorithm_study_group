// 크리스마스 선물 bj.14235
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, a, value;
    priority_queue<int> q;

    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> a;
        if (a == 0)
        {
            if (q.empty())
                cout << "-1\n";
            else
            {
                cout << q.top() << '\n';
                q.pop();
            }
        }
        else
        {
            for (int j=0; j<a; j++)
            {
                cin >> value;
                q.push(value);
            }
        }
    }
    return (0);
}