// 병든 나이트 bj.1783
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int count_block(int n, int m)
{
	if (n <= 1) return (1);
	if (n == 2) {
		if (m < 3) return (1);
		else if (m <= 7) return ((m - 1) / 2 + 1);
		else return (4);
	}
	// if n >= 3
	if (m <= 4) return (m);
	else if (m <= 6) return (4);
	else return (5 + (m - 7));
}

int main()
{
	fast;
	int n, m;

	cin >> n >> m;
	cout << count_block(n, m);
	return (0);
}