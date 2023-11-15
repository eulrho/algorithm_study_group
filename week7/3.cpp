// 나무 자르기 bj.2805
#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

long long wood(long long *trees, int n, long long mid)
{
    long long temp=0;

    for (int i=0; i<n; i++) {
        if (trees[i] - mid > 0) temp += trees[i] - mid;
    }
    return (temp);
}

int find_target(long long target, long long *trees, int n, long long left, long long right)
{
    long long mid, temp;

    while (left <= right) {
        mid = (left + right) / 2;
        temp = wood(trees, n, mid);
        if (temp >= target) {
            if (mid == trees[n-1] || wood(trees, n, mid + 1) < target) return (mid);
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
    cin >> n >> m;
    long long *trees = new long long[n];
    for (int i=0; i<n; i++)
        cin >> trees[i];
    sort(trees, trees+n);
    cout << find_target(m, trees, n, 0, trees[n-1]);
    delete []trees;
    return (0);
}