// 타노스는 요세푸스가 밉다 bj.28066
#include <iostream>
#include <deque>

using namespace std;

void kill(deque<int> &q, int K)
{
    while (q.size() > K)
    {
        q.push_back(q.front());
        for (int i=0; i<K; i++)
            q.pop_front();
    }
}

void initialize_queue(deque<int> &q, int N)
{
    for (int i=1; i<=N; i++)
        q.push_back(i);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K;
    deque<int> q;

    cin >> N >> K;
    initialize_queue(q, N);
    kill(q, K);
    cout << q.front();
    return (0);
}