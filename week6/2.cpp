// 알고리즘 수업 - 버블 정렬 1 bj.23968
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

void bubble_sort(int *a, int n, int k)
{
    int cnt=0;

    for (int last=n; last>=2; last--) {
        for (int i=1; i<last; i++) {
            if (a[i] > a[i+1]) {
                cnt++;
                if (cnt == k) print_result(a[i], a[i+1]);
                swap_a(&a[i], &a[i+1]);
            }
        }
    }
    if (cnt < k) cout << -1;
}

int main()
{
    int n, k;
    int a[10001];

    cin >> n >> k;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    bubble_sort(a, n, k);
    return (0);
}