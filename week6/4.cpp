// 알고리즘 수업 - 병합 정렬 1 bj.24060
#include <iostream>
using namespace std;

void merge(int *a, int left, int mid, int right, int k, int *cnt)
{
    int i = left, j = mid + 1, t = 1;
    int *tmp = new int[right + 1];

    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) tmp[t++] = a[i++];
        else tmp[t++] = a[j++];
    }
    while (i<=mid) tmp[t++] = a[i++];
    while (j<=right) tmp[t++] = a[j++];
    i = left, t = 1;
    while (i<=right) {
        if (++(*cnt) == k)
            cout << tmp[t];
        a[i++] = tmp[t++];
    }
    delete []tmp;
}

void merge_sort(int *a, int left, int right, int k, int *cnt)
{
    int mid;

    if (left < right) {
        mid = (left + right) / 2;
        merge_sort(a, left, mid, k, cnt);
        merge_sort(a, mid + 1, right, k, cnt);
        merge(a, left, mid, right, k, cnt);
    }
}

int main()
{
    int n, k, cnt=0;
    int a[500001];

    cin >> n >> k;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    merge_sort(a, 1, n, k, &cnt);
    if (cnt < k) cout << -1;
    return (0);
}