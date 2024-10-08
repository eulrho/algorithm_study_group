// 행복 유치원 bj.13164
#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, k; cin >> n >> k;

	int diff[n], front=0, back;
	for (int i=0; i<n; i++) {
		if (i == 0) cin >> front;
		else {
			cin >> back;
			diff[i] = back - front;
			front = back;
		}
	}
	sort(diff+1, diff+n);
	int sum=0;
	for (int i=0; i<n-k; i++) sum += diff[i+1];
	cout << sum;
	return 0;
}