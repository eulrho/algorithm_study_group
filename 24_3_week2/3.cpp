// 게으른 백곰 bj.10025
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int arr[1000001];

int find_ice(int k, int max_pos)
{
	int left = 1, right = 2 * k + 1, sum, max=0;

	while (right <= max_pos) {
		sum = arr[right] - arr[left-1];
		max = max < sum ? sum : max;
		left++; right++;
	}
	return (max);
}

int main()
{
	fast;
	int n, k, g, x, max_pos=0;

	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> g >> x;
		max_pos = max_pos < x ? x : max_pos;
		arr[x] = g;
	}
	for (int i=1; i<=max_pos; i++)
		arr[i] += arr[i-1];
	if (2 * k + 1 >= max_pos) cout << arr[max_pos];
	else cout << find_ice(k, max_pos);
	return (0);
}