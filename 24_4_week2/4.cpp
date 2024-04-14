// 행복 유치원 bj.13164
#include <iostream>
#include <algorithm>
using namespace std;
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int diff_arr[300000];

int main()
{
	fast;
	int n, k, front=0, back=0, idx=0, sum=0;

	cin >> n >> k;
	for (int i=0; i<n; i++) {
		if (front == 0)
			cin >> front;
		else {
			cin >> back;
			diff_arr[idx] = back - front;
			front = back;
			idx++;
		}
	}
	sort(diff_arr, diff_arr + (n - 1));
	for (int i=0; i<n-1-(k-1); i++)
		sum += diff_arr[i];
	cout << sum;
	return (0);
}
