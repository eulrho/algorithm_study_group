// 사냥꾼 bj.8983
#include <iostream>
#include <cmath>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

long long positions[100000];
int cnt;

void find_cnt_animals(int m, long long l, long long x, long long y)
{
	int left=0, right=m-1, mid;

	while (left <= right) {
		mid = (left + right) / 2;
		if (abs(positions[mid] - x) + y <= l) {
			cnt++;
			break ;
		}
		if (positions[mid] >= x) right = mid - 1;
		else left = mid + 1;
	}
}

int main()
{
	fast;
	int m, n;
	long long l, y, x;

	cin >> m >> n >> l;
	for (int i=0; i<m; i++) cin >> positions[i];
	sort(positions, positions + m);
	for (int i=0; i<n; i++) {
		cin >> x >> y;
		find_cnt_animals(m, l, x, y);
	}
	cout << cnt;
	return (0);
}