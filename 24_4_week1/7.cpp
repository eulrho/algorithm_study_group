// 휴게소 세우기 bj.1477
#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int check_mid(int mid, int *rest_area, int m, int l)
{
	int idx=0, cnt=0, location=mid;

	while (location <= l - 1) {
		if (location >= rest_area[idx]) {
			location = rest_area[idx] + mid;
			idx++;
		}
		else {
			cnt++;
			location += mid;
		}
	}
	if (cnt <= m) return (1);
	else return (0);
}

int binary_search(int m, int l, int rest_area[], int left, int right)
{
	int mid, min=right, temp;

	while (left <= right) {
		mid = (left + right) / 2;
		temp = check_mid(mid, rest_area, m, l);
		if (temp == 1) {
			min = min > mid ? mid : min;
			right = mid - 1;
		}
		else left = mid + 1;
	}
	return (min);
}

int main()
{
	fast;
	int n, m, l, max=0;
	int rest_area[51];

	cin >> n >> m >> l;
	for (int i=0; i<n; i++) {
		cin >> rest_area[i];
		if (i == 0)
			max = rest_area[0] > l - rest_area[0] ? rest_area[0] : l - rest_area[0];
		else
			max = max < rest_area[i] - rest_area[i-1] ? rest_area[i] - rest_area[i-1] : max;
	}
	rest_area[n] = l;
	sort(rest_area, rest_area+n);
	if (n == 0) max = l;
	cout << binary_search(m, l, rest_area, 1, max);
	return (0);
}