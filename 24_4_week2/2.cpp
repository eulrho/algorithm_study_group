// 카드 합체 놀이 bj.15903
#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

long long arr[1001];
int h_size=1;

void push_heap(long long num)
{
	arr[h_size++] = num;
	for (int i=h_size-1; i/2>=1;) {
		if (arr[i/2] > arr[i]) {
			swap(arr[i/2], arr[i]);
			i /= 2;
		}
		else break ;
	}
}

long long pop_heap()
{
	long long res;
	int child;

	res = arr[1];
	arr[1] = arr[h_size - 1];
	h_size--;
	for (int i=1; i*2<h_size;) {
		child = i*2;
		if (i*2+1 < h_size && arr[i*2] > arr[i*2+1]) child = i*2+1;
		if (arr[i] > arr[child]) {
			swap(arr[i], arr[child]);
			i = child;
		}
		else break ;
	}
	return (res);
}

int main()
{
	fast;
	int n, m;
	long long temp1, temp2, sum=0, num;

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> num;
		push_heap(num);
	}
	for (int i=0; i<m; i++) {
		temp1 = pop_heap();
		temp2 = pop_heap();
		push_heap(temp1 + temp2);
		push_heap(temp1 + temp2);
	}
	for (int i=1; i<=n; i++)
		sum += arr[i];
	cout << sum;
	return (0);
}