// 사냥꾼 bj.8983
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

long long is_kill(pair<int, int>a, int pos)
{
    return (abs(pos - a.second) + a.first);
}

int find_target(long long target, int *pos, pair<int, int> a, int left, int right)
{
    int mid;
    long long temp;

    while (left <= right) {
        mid = (left + right) / 2;
        temp = is_kill(a, pos[mid]);
        if (temp <= target) return (1);
        if (pos[mid] < a.second) left = mid + 1;
        else right = mid - 1;
    }
    return (0);
}

int main()
{
    fast;
    int m, n, x, y, result=0;
    long long l;
    vector<pair<int, int>>animal;
    cin >> m >> n >> l;

    int *position = new int[m];
    for (int i=0; i<m; i++) cin >> position[i];
    for (int i=0; i<n; i++) {
        cin >> x >> y;
        animal.push_back(make_pair(y, x));
    }
    sort(position, position+m);
    for (auto a : animal)
        result += find_target(l, position, a, 0, m-1);
    cout << result;
    delete []position;
    return (0);
}