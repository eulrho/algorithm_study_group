// 수 찾기 bj.1920
#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int find_target(int target, int *sample, int n)
{
    int left = 0, right = n - 1, mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (sample[mid] == target) return (1);
        else if (sample[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return (0);
}

int main()
{
    fast;
    int n, m;

    cin >> n;
    int *sample = new int[n];
    for(int i=0; i<n; i++) cin >> sample[i];
    cin >> m;
    int *target = new int[m];
    for(int i=0; i<m; i++) cin >> target[i];
    sort(sample, sample+n);
    for(int i=0; i<m; i++) cout << find_target(target[i], sample, n) << '\n';
    delete []target;
    delete []sample;
    return (0);
}