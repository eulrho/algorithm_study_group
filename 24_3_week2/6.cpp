// 회전 초밥 bj.2531
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int arr[30001];

int find_ways(int n, int k, int c)
{
	int left=0, right=k, cnt, max=0, flag, temp_l;

	while (left < n) {
		bool sushi[3001]={false,};

		cnt = 0;
		flag = 0;

		temp_l = left;
		while (temp_l != right) {
			if (!sushi[arr[temp_l]]) {
				sushi[arr[temp_l]] = true;
				cnt++;
			}
			if (arr[temp_l] == c) flag = 1;
			if (temp_l == n - 1) temp_l = 0;
			else temp_l++;
		}
		if (flag == 0) cnt++;
		max = max < cnt ? cnt : max;
		left++;
		if (right == n - 1) right = 0;
		else right++;
	}
	return (max);
}

int main()
{
	fast;
	int n, d, k, c;

	cin >> n >> d >> k >> c;
	for (int i=0; i<n; i++) cin >> arr[i];
	cout << find_ways(n, k, c);
	return (0);
}