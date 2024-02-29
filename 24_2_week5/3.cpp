// 초콜릿 자르기 bj.2163
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, m, res=0;

	cin >> n >> m;
	if (n == 1 && m == 1) {
		cout << 0;
		return (0);
	}
	if (n != 1) res += n - 1;
	if (m != 1) res += n * (m - 1);
	cout << res;
	return (0);
}