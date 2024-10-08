// 휴게소 세우기 bj.1477
#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n, m, l;

bool is_max(int *arr, int mid)
{
	int cnt = 0, target = 0, idx=0;

	while (target + mid < l) {
		int new_target = l;
		for (; idx<n; idx++) {
			if (arr[idx] >= target + mid)
			{
				new_target = arr[idx];
				break ;
			}
			else target = arr[idx];
		}

		int tmp = target + mid;
		if (tmp >= l) break ;
		if (new_target == tmp) {
			target = new_target;
			continue ;
		}
		if (new_target - tmp > mid)
			target = tmp;
		else target = new_target;
		cnt++;
	}
	return cnt <= m;
}

int find_min_of_max(int *arr)
{
	int mid, left = 1, right=l, res=right;

	while (left < right) {
		mid = (left + right) / 2;
		if (is_max(arr, mid)) {
			res = min(res, mid);
			right = mid;
		}
		else left = mid + 1;
	}
	return res;
}

int main()
{
	fast;
	cin >> n >> m >> l;

	int arr[n];
	for (int i=0; i<n; i++)
		cin >> arr[i];
	sort(arr, arr+n);

	for (int i=0; i<n; i++)
		cin >> arr[i];
	cout << find_min_of_max(arr);
	return 0;
}