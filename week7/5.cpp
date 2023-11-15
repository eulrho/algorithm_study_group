// 용돈 관리 bj.6236
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int money(int *arr, int n, long long mid)
{
    int temp = 1;
    long long total = mid;
    for (int i=0; i<n; i++) {
        if ((long long)arr[i] > total) {
            temp++;
            total = mid;
        }
        total -= (long long)arr[i];
    }
    return (temp);
}

int find_target(int target, int *arr, int n, long long left, long long right)
{
    long long mid, min = left;
    int temp;

    while (left <= right) {
        mid = (left + right) / 2;
        temp = money(arr, n, mid);
        if (temp <= target) {
            if (mid == min || money(arr, n, mid - 1) > target) return (mid);
            else right = mid - 1;
        }
        else left = mid + 1;
    }
    return (0);
}

int main()
{
    fast;
    int n, m;
    long long sum=0, max=0;

    cin >> n >> m;
    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        sum += (long long)arr[i];
        if (max < (long long)arr[i]) max = (long long)arr[i];
    }
    cout << find_target(m, arr, n, max, sum) << '\n';
    delete []arr;
    return (0);
}