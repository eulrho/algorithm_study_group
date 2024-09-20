// 사냥꾼 bj.8983
#include <iostream>
#include <cmath>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

long m, n, l;

long find_distance(long pos, long x, long y)
{
	return abs(pos - x) + y;
}

bool binary_search(long *position, long x, long y) {
	long left = 0, right = m-1, mid;

	while (left <= right) {
		mid = (left + right) / 2;
		if (find_distance(position[mid], x, y) <= l)
			return true;
		if (position[mid] > x) right = mid - 1;
		else left = mid + 1;
	}
	return false;
}

int main()
{
	fast;
	cin >> m >> n >> l;

	long position[m];
	for (long i=0; i<m; i++) cin >> position[i];
	sort(position, position + m);

	long x, y, cnt=0;
	for (long i=0; i<n; i++) {
		cin >> x >> y;
		if (binary_search(position, x, y))
			cnt++;
	}
	cout << cnt;
	return (0);
}