// 알고리즘 수업 - 퀵 정렬 1 bj.24090
#include <iostream>
using namespace std;

void swap_a(int *num_a, int *num_b)
{
    int temp;

    temp = *num_a;
    *num_a = *num_b;
    *num_b = temp;
}

void print_result(int i, int j)
{
    int small = i, big = j;
    if (i > j) swap_a(&small, &big);
    cout << small << ' ' << big;
}

int partition(int *a, int left, int right, int k, int *cnt)
{
    int pivot = a[right];
    int low = left - 1;
    for (int j=left; j<right; j++) {
        if (a[j] <= pivot) {
            low++;
            if (++(*cnt) == k) print_result(a[low], a[j]);
            swap_a(&a[low], &a[j]);
        }
    }
    if (low + 1 != right) {
        if (++(*cnt) == k) print_result(a[low + 1], a[right]);
        swap_a(&a[low + 1], &a[right]);
    }
    return (low + 1);
}

void quick_sort(int *a, int left, int right, int k, int *cnt)
{
    int pivot_idx;

    if (left < right) {
        pivot_idx = partition(a, left, right, k, cnt);
        quick_sort(a, left, pivot_idx - 1, k, cnt);
        quick_sort(a, pivot_idx + 1, right, k, cnt);
    }
}

int main()
{
    int n, k, cnt=0;
    int a[500001];

    cin >> n >> k;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    quick_sort(a, 1, n, k, &cnt);
    if (cnt < k) cout << -1;
    return (0);
}