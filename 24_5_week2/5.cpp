// 좋다 bj.1253
#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int arr[2001];

bool is_good_number(int n, int target)
{
	int left=0, right=n-1, sum;

	while (left < right) {
		sum = arr[left] + arr[right];
		if (target != left && target != right && sum == arr[target])
			return (true);
		if (sum < arr[target]) left++;
		else if (sum > arr[target]) right--;
		else {
			if (left == target) left++;
			else right--;
		}
	}
	return (false);
}

int main()
{
	fast;
	int n, cnt=0;

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> arr[i];
	if (n <= 2) {
		cout << 0;
		return (0);
	}
	sort(arr, arr+n);
	for (int i=0; i<n; i++) {
		if (is_good_number(n, i)) cnt++;
	}
	cout << cnt;
	return (0);
}
