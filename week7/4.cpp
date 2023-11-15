// 예산 bj.2512
#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

long long budget(long long *arr, int n, long long mid)
{
    long long temp=0;

    for (int i=0; i<n; i++) {
        if (arr[i] > mid) temp += mid;
        else temp += arr[i];
    }
    return (temp);
}

int find_target(long long target, long long *arr, int n, long long left, long long right)
{
    long long mid, temp;

    while (left <= right) {
        mid = (left + right) / 2;
        temp = budget(arr, n, mid);
        if (temp <= target) {
            if (mid == arr[n-1] || budget(arr, n, mid + 1) > target) return (mid);
            else left = mid + 1;
        }
        else right = mid - 1;
    }
    return (0);
}

int main()
{
    fast;
    int n;
    long long m;
    cin >> n;
    long long *arr = new long long[n];
    for (int i=0; i<n; i++)
        cin >> arr[i];
    cin >> m;
    sort(arr, arr+n);
    cout << find_target(m, arr, n, 0, arr[n-1]);
    delete []arr;
    return (0);
}