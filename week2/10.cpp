// 프린터 큐 bj.1966
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_cnt(vector<int> &q, vector<int> &priority, int M)
{
    int temp, cnt;

    cnt = 0;
    while (!q.empty())
    {
        if (q.front() == priority.front())
        {
            q.erase(q.begin());
            priority.erase(priority.begin());
            cnt++;
            if (M == 0)
                break ;
            else
                M--;
        }
        else
        {
            temp = q.front();
            q.erase(q.begin());
            q.push_back(temp);
            if (M == 0)
                M = q.size() - 1;
            else
                M--;
        }
    }
    q = vector<int>();
    priority = vector<int>();
    return (cnt);
}

void initialize_queue(vector<int> &q, vector<int>&priority, int *M)
{
    int docu_n, pr;

    cin >> docu_n >> *M;
    for (int i=0; i<docu_n; i++)
    {
        cin >> pr;
        q.push_back(pr);
    }
    priority = q;
    sort(priority.begin(), priority.end());
    reverse(priority.begin(), priority.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, cnt, M;
    vector<int> q;
    vector<int> priority;

    cin >> N;
    while (--N >= 0)
    {
        initialize_queue(q, priority, &M);
        cnt = find_cnt(q, priority, M);
        cout << cnt << '\n';
    }
    return (0);
}