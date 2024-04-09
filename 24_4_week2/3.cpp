// 리모컨 bj.1107
#include <iostream>
#include <algorithm>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n, m, arr[10], min_cnt, n_len;

int num_len(int num)
{
	int i = num==0;

	while (num) {
		num /= 10;
		i++;
	}
	return (i);
}

bool is_broken(int num)
{
	for (int j=0; j<m; j++) {
		if (num == arr[j]) return (true);
	}
	return (false);
}

void find_target(int target, int len)
{
	if (len >= 1 && len >= n_len - 1 && len <= n_len + 1) {
		int temp = len + abs(target - n);
		min_cnt = temp < min_cnt ? temp : min_cnt;
		if (len == n_len + 1)
			return ;
	}
	for (int i=0; i<=9; i++) {
		if (!is_broken(i))
			find_target(target * 10 + i, len + 1);
	}
}

int main()
{
	fast;
	cin >> n >> m;
	n_len = num_len(n);
	for (int i=0; i<m; i++) cin >> arr[i];
	sort(arr, arr+m);
	min_cnt = abs(100 - n);
	find_target(0, 0);
	cout << min_cnt;
	return (0);
}