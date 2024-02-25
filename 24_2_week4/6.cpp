// 구간 합 구하기 4 bj.11659
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int arr[100001];

int main()
{
	fast;
	int n, t, start, end, num;

	cin >> n >> t;
	for (int i=1; i<=n; i++) {
		cin >> num;
		arr[i] = arr[i-1] + num;
	}
	for (int i=0; i<t; i++) {
		cin >> start >> end;
		cout << arr[end] - arr[start - 1] << '\n';
	}
	return (0);
}