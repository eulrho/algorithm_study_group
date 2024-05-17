// 아 저는 볶음밥이요 bj.23814
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

long long d, n, m, k;

long long find_max_cnt()
{
	long long max_cnt, cur_cnt;

	max_cnt = (n + m + k) / d;
	cur_cnt = n / d + m / d;
	n %= d;
	m %= d;
	if (k / d + cur_cnt == max_cnt) return (k);
	if (n > m) {
		if (d - n <= k) {
			k -= (d - n);
			cur_cnt++;
		}
		if (k / d + cur_cnt == max_cnt) return (k);
		if (m != 0 && d - m <= k) {
			k -= (d - m);
			cur_cnt++;
		}
		if (k / d + cur_cnt == max_cnt) return (k);
	}
	else {
		if (d - m <= k) {
			k -= (d - m);
			cur_cnt++;
		}
		if (k / d + cur_cnt == max_cnt) return (k);
		if (n != 0 && d - n <= k) {
			k -= (d - n);
			cur_cnt++;
		}
		if (k / d + cur_cnt == max_cnt) return (k);
	}
	return (0);
}

int main()
{
	fast;

	cin >> d >> n >> m >> k;
	cout << find_max_cnt();
	return (0);
}

