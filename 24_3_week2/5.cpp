// 고양이 카페 bj.28353
#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int arr[5001];

int find_count(int n, int k)
{
	int left=0, right=n-1, weight, cnt=0;

	while (left < right) {
		weight = arr[left] + arr[right];
		if (weight <= k) {
			left++;
			right--;
			cnt++;
		}
		else right--;
	}
	return (cnt);
}

int main()
{
	fast;
	int n, k;

	cin >> n >> k;
	for (int i=0; i<n; i++) cin >> arr[i];
	sort(arr, arr+n);
	cout << find_count(n, k);
	return (0);
}