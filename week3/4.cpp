// 최대힙 bj.11279
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, x;
    priority_queue<int, vector<int>, less<int>> q;

    cin >> N;
    for (int i=0; i<N; i++)
    {
        cin >> x;
        if (x != 0)
            q.push(x);
        else
        {
            if (q.empty())
                cout << "0\n";
            else
            {
                cout << q.top() << '\n';
                q.pop();
            }
        }
    }
}