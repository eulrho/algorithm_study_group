// 배열 합치기 bj.11728
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int a[1000001];
int b[1000001];

int main()
{
	fast;
	int n, m, a_idx=0, b_idx=0;

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<m; i++)
		cin >> b[i];
	while (a_idx <= n-1 && b_idx <= m-1) {
		if (a[a_idx] < b[b_idx]) {
			cout << a[a_idx] << ' ';
			a_idx++;
		}
		else if (a[a_idx] > b[b_idx]) {
			cout << b[b_idx] << ' ';
			b_idx++;
		}
		else {
			cout << a[a_idx] << ' ' << b[b_idx] << ' ';
			a_idx++;
			b_idx++;
		}
	}
	if (a_idx <= n-1) {
		for (int i=a_idx; i<n; i++) cout << a[i] << ' ';
	}
	if (b_idx <= m-1) {
		for (int i=b_idx; i<m; i++) cout << b[i] << ' ';
	}
	return (0);
}
