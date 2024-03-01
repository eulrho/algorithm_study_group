// 사냥꾼 bj.8983
#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int m, n;
long long l, x, y;
long long gun[100001];

int check(long long mid)
{
	if (x + y - l <= gun[mid] && gun[mid] <= x - y + l) return (1);
	else if (x + y - l > gun[mid]) return (2);
	else return (3);
}

int binary_search(long long left, long long right)
{
	long long mid;
	int temp;

	while (left <= right) {
		mid = (left + right) / 2;
		temp = check(mid);
		if (temp == 1) return (1);
		else if (temp == 2) left = mid + 1;
		else right = mid - 1;
	}
	return (0);
}

int main()
{
	fast;
	int count = 0;

	cin >> m >> n >> l;
	for (int i=0; i<m; i++)
		cin >> gun[i];
	sort(gun, gun+m);
	for (int i=0; i<n; i++)
	{
		cin >> x >> y;
		count += binary_search(0, m-1);
	}
	cout << count;
	return (0);
}