// 회의실 배정 bj.1931
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.first == p2.first) return (p1.second < p2.second);
    else return (p1.first < p2.first);
}

int main()
{
    fast;
    int n, start, end, cnt=1;
    vector<pair<int, int>> time_lst;

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> start >> end;
        time_lst.emplace_back(start, end);
    }
    sort(time_lst.begin(), time_lst.end(), cmp);
    end = time_lst.back().first;
    for (int i=n-2; i>=0; i--) {
        if (time_lst[i].second <= end) {
            cnt++;
            end = time_lst[i].first;
        }
    }
    cout << cnt;
    return (0);
}