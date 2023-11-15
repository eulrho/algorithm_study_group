// 숫자 카드 2 bj.10816
#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int find_target_up(int target, int *sample, int n)
{
    int left = 0, right = n - 1, mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (sample[mid] == target) {
            if (mid == n-1 || (mid + 1 < n && sample[mid+1] != target))
                return (mid);
        }
        if (sample[mid] <= target) left = mid + 1;
        else right = mid - 1;
    }
    return (-1);
}

int find_target_down(int target, int *sample, int n)
{
    int left = 0, right = n - 1, mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (sample[mid] == target) {
            if (mid == 0 || (mid - 1 >= 0 && sample[mid-1] != target))
                return (mid);
        }
        if (sample[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return (-1);
}

int main()
{
    fast;
    int n, m, temp;

    cin >> n;
    int *sample = new int[n];
    for(int i=0; i<n; i++) cin >> sample[i];
    cin >> m;
    int *target = new int[m];
    for(int i=0; i<m; i++) cin >> target[i];
    sort(sample, sample+n);
    for(int i=0; i<m; i++) {
        temp = find_target_up(target[i], sample, n);
        if (temp != -1) {
            temp = temp - find_target_down(target[i], sample, n) + 1;
        }
        else temp = 0;
        cout << temp << ' ';
    }
    delete []target;
    delete []sample;
    return (0);
}