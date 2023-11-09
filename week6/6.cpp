// 알고리즘 수업 - 힙 정렬 1 bj.24173
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

void heapify(int *a, int parent, int n, int k, int *cnt)
{
    int left = 2 * parent;
    int right = 2 * parent + 1;
    int smaller;

    // 자식 노드 중 작은 노드 탐색
    if (right <= n) {
        if (a[left] < a[right]) smaller = left;
        else smaller = right;
    }
    else if (left <= n) smaller = left;
    else return ;
    // 자식 노드가 더 작을 경우 부모 노드와 교환
    if (a[smaller] < a[parent]) {
        if (++(*cnt) == k) print_result(a[parent], a[smaller]);
        swap_a(&a[parent], &a[smaller]);
        heapify(a, smaller, n, k, cnt);
    }
}

void build_mid_heap(int *a, int n, int k, int *cnt)
{
    for (int i=n/2; i>=1; i--) heapify(a, i, n, k, cnt);
}

void heap_sort(int *a, int n, int k, int *cnt)
{
    // a[1]에 최솟값 정렬
    build_mid_heap(a, n, k, cnt);
    // 최솟값 뒤로 보내기(내림차순)
    for (int i=n; i>=2; i--) {
        if (++(*cnt) == k) print_result(a[1], a[i]);
        swap_a(&a[1], &a[i]);
        heapify(a, 1, i - 1, k, cnt);
    }
}

int main()
{
    int n, k, cnt=0;
    int a[500001];

    cin >> n >> k;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    heap_sort(a, n, k, &cnt);
    if (cnt < k) cout << -1;
    return (0);
}