// 요세푸스 문제 0 bj.11866
#include <iostream>
#include <queue>

using namespace std;

void del_cnt(queue<int> &q, int K, int N)
{
    int temp, cnt = 1;

    while (!q.empty())
    {
        if (cnt == K)
        {
            cout << q.front();
            q.pop();
            if (!q.empty()) {
                cout << ", ";
            }
            cnt = 0;
        }
        else
        {
            temp = q.front();
            q.pop();
            q.push(temp);
        }
        cnt++;
    }
}

void initialize_queue(queue<int> &q, int N)
{
    for (int i=1; i<=N; i++)
        q.push(i);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K;
    queue<int> q;

    cin >> N >> K;
    initialize_queue(q, N);
    cout << '<';
    del_cnt(q, K, N);
    cout << '>';
    return (0);
}