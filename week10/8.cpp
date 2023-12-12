// 후보 추천하기 bj.1713
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int find_idx(vector<pair<int, int>> v, int num)
{
    for (int i=0; i<v.size(); i++) {
        if (v[i].first == num) return (i);
    }
    return (-1);
}

int main(void)
{
    fast;
    int n, recom, student, idx, min_idx, min;
    vector<pair<int, int > > frame;

    cin >> n >> recom;
    for (int i=0; i<recom; i++) {
        cin >> student;
        idx = find_idx(frame, student);
        if (idx != -1) {
            frame[idx].second++;
        }
        else if (frame.size() < n) {
            frame.push_back(make_pair(student, 1));
        }
        else {
            min = 1000;
            for (int j=n-1; j>=0; j--) {
                if (frame[j].second <= min) {
                    min = frame[j].second;
                    min_idx = j;
                }
            }
            frame.erase(frame.begin()+min_idx);
            frame.push_back(make_pair(student, 1));
        }
    }
    sort(frame.begin(), frame.end());
    for (int i=0; i<frame.size(); i++)
        cout << frame[i].first << ' ';
    return (0);
}