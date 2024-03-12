// 주몽 bj.1940
#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int arr[15001];

int count_armors(int n, int m)
{
	int cnt=0;
	int left=0, right=n-1;

	while (left < right) {
		if (arr[left] + arr[right] == m) {
			cnt++;
			left++;
			right--;
		}
		else if (arr[left] + arr[right] > m)
			right--;
		else left++;
	}
	return (cnt);
}

int main()
{
	fast;
	int n, m;

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> arr[i];
	sort(arr, arr+n);
	cout << count_armors(n, m);
	return (0);
}