// 입국심사 bj.3079
#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

long long immigration(long long *arr, long long n, long long mid)
{
    long long cnt=0, sum;

    for (int i=0; i<n; i++) {
        sum = mid / arr[i];
        if (sum == 0) break ;
        cnt += sum;
    }
    return (cnt);
}

long long find_target(long long target, long long *arr, long long n, long long left, long long right)
{
    long long mid, min = left, temp;

    while (left <= right) {
        mid = (left + right) / 2;
        temp = immigration(arr, n, mid);
        if (temp >= target) {
            if (mid == min || immigration(arr, n, mid - 1) < target) return (mid);
            else right = mid - 1;
        }
        else left = mid + 1;
    }
    return (0);
}

int main()
{
    fast;
    long long n, m;
    cin >> n >> m;

    long long *arr = new long long[n];
    for (int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    cout << find_target(m, arr, n, arr[0], arr[0]*m);
    delete []arr;
    return (0);
}