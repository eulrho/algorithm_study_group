// 알고리즘 수업 - 선택 정렬 1 bj.23881
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

void selection_sort(int *a, int n, int k)
{
    int max, max_idx, cnt=0;

    for (int last=n; last>=2; last--) {
        max = a[last];
        max_idx = last;
        for (int j=1; j<=last; j++) {
            if (max < a[j]) {
                max = a[j];
                max_idx = j;
            }
        }
        if (last != max_idx){
            cnt++;
            if (cnt == k)
                print_result(a[last], a[max_idx]);
            swap_a(&a[last], &a[max_idx]);
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
    selection_sort(a, n, k);
    return (0);
}