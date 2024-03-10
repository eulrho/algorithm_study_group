// 두 용액 bj.2470
#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int arr[100001];

void find_value(int n)
{
	int left, right, min, liquid[2];

	left = 0, right = n-1, min = -2000000000;
	while (left < right) {
		if (abs(arr[left] + arr[right]) < abs(min)) {
			liquid[0] = arr[left]; liquid[1] = arr[right];
			min = arr[left] + arr[right];
		}
		if (abs(arr[left + 1] + arr[right]) < abs(arr[left] + arr[right - 1]))
			left += 1;
		else right -= 1;
	}
	cout << liquid[0] << ' ' << liquid[1];
}

int main()
{
	fast;
	int n;

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> arr[i];
	sort(arr, arr+n);
	find_value(n);
	return (0);
}
