// 암기왕 bj.2776
#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int arr[1000000];

int binary_search(int target, int max)
{
	int left = 0, right = max - 1, mid;

	while (left <= right) {
		mid = (left + right) / 2;
		if (arr[mid] == target) return (1);
		if (arr[mid] > target) right = mid - 1;
		else left = mid + 1;
	}
	return (0);
}

int main()
{
	fast;
	int t, n, m, sample;

	cin >> t;
	for (int i=0; i<t; i++) {
		cin >> n;
		for (int j=0; j<n; j++) cin >> arr[j];
		sort(arr, arr+n);
		cin >> m;
		for (int j=0; j<m; j++) {
			cin >> sample;
			cout << binary_search(sample, n) << '\n';
		}
	}
	return (0);
}