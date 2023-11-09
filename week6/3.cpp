// 알고리즘 수업 - 삽입 정렬 1 bj.24051
#include <iostream>
using namespace std;

void print_result(int num)
{
    cout << num;
}

void insertion_sort(int *a, int n, int k)
{
    int cnt=0, loc, newItem;

    for (int i=2; i<=n; i++) {
        loc = i-1;
        newItem = a[i];
        while (1<=loc && newItem < a[loc]) {
            a[loc+1] = a[loc];
            if (++cnt == k) print_result(a[loc]);
            loc--;
        }
        if (loc + 1 != i) {
            a[loc + 1] = newItem;
            if (++cnt == k) print_result(newItem);
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
    insertion_sort(a, n, k);
    return (0);
}