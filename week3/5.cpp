// 절댓값 힙 bj.11286
#include <iostream>
#include <queue>

using namespace std;

struct compare
{
    // true -> swap
    bool operator() (int a, int b) {
        int abs_a = a < 0 ? a * -1 : a;
        int abs_b = b < 0 ? b * -1 : b;
        if (abs_a == abs_b)
            return (a > b);
        else
            return (abs_a > abs_b);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, x;
    priority_queue<int, vector<int>, compare> q;

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