// 통나무 건너뛰기 bj.11497
#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int t, n, height, max, temp;
    vector<int> wood;

    cin >> t;
    for (int i=0; i<t; i++) {
        max = -1;
        wood = vector<int> ();
        cin >> n;
        for (int j=0; j<n; j++) {
            cin >> height;
            wood.push_back(height);
        }
        sort(wood.begin(), wood.end());
        for (int j=0; j < n; j++) {
            temp = j + 2;
            if (temp >= n) temp -= n - 1;
            if (wood[temp] - wood[j] > max)
                max = wood[temp] - wood[j];
        }
        cout << max << '\n';
    }
    return (0);
}