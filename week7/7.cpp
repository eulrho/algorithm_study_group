// 공유기 설치 bj.2110
#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int count(int *arr, int n, int mid)
{
    int temp=1, standard=arr[0];

    for (int i=0; i<n-1; i++) {
        if (arr[i+1] - standard >= mid) {
            standard = arr[i+1];
            temp++;
        }
    }
    return (temp);
}

int find_target(int target, int *arr, int n, int left, int right)
{
    int max, temp, mid;

    max = right;
    while (left <= right) {
        mid = (left + right) / 2;
        temp = count(arr, n, mid);
        if (temp >= target) {
            if (mid == max || count(arr, n, mid + 1) < target) return (mid);
            else left = mid + 1;
        }
        else right = mid - 1;
    }
    return (0);
}

int main()
{
    fast;
    int n, c;
    cin >> n >> c;

    int *home = new int[n];
    for (int i=0; i<n; i++) cin >> home[i];

    sort(home, home+n);
    cout << find_target(c, home, n, 1, home[n-1]-home[0]);
    delete []home;
    return (0);
}