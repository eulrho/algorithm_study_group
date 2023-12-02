// 두 용액 bj.2470
#include <iostream>
#include <algorithm>
#include <cmath>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int m=2000000001;
int result[2];

void bs(int *arr, int target, int start, int end)
{
    int left, right, mid;

    left = start, right = end;
    while (left <= right) {
        mid = (left + right) / 2;
        if (abs(arr[mid] + arr[target]) < m) {
            m = abs(arr[mid] + arr[target]);
            result[0] = arr[target];
            result[1] = arr[mid];
        }
        if (arr[mid] + arr[target] < 0) left = mid + 1;
        else right = mid - 1;
    }
}

int main()
{
    fast;
    int n;
    int arr[100000];

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    for (int i=0; i < n - 1; i++) {
        bs(arr, i, i + 1, n-1);
    }
    sort(result, result+2);
    cout << result[0] << ' ' << result[1];
    return (0);
}
// -100 -50 20 40 80