// N번째 큰 수 bj.2075
#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<int, vector<int>, greater<int>> q;

    int N, nb;

    cin >> N;
    for (int i=0; i<N*N; i++)
    {
        cin >> nb;
        q.push(nb);
        if (i >= N)
            q.pop();
    }
    cout << q.top();
    return (0);
}