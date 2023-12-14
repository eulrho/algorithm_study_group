// 신입 사원 bj.1946
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int t, n, score, ranking, min, cnt;
    vector<pair<int, int>> recruit;

    cin >> t;
    for (int i=0; i<t; i++) {
        min=100001;
        cnt=0;
        recruit = vector<pair<int, int>> ();
        cin >> n;
        for (int j=0; j<n; j++) {
            cin >> score >> ranking;
            recruit.emplace_back(ranking, score);
        }
        sort(recruit.begin(), recruit.end());
        for (int j=0; j<n; j++) {
            if (min >= recruit[j].second) {
                cnt++;
                min = recruit[j].second;
            }
        }
        cout << cnt << '\n';
    }
    return (0);
}