// XORXORXOR bj.12833
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int a, b, c;

	cin >> a >> b >> c;
	if (c % 2 == 0) cout << a;
	else cout << (a ^ b);
	return (0);
}
