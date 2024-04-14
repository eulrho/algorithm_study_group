// Moo 게임 bj.5904
#include <iostream>
#include <string>
using namespace std;
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

string moo = "moo";

void moo_game(int n, int before_len, int k)
{
	int new_len;

	if (n <= 3) cout << moo[n-1];
	else if (n <= before_len)
		moo_game(n, (before_len - 2 - k) / 2, k - 1);
	else if (n == before_len + 1) cout << moo[0];
	else if (n <= before_len + 3 + k) cout << moo[1];
	else {
		new_len = before_len * 2 + 3 + k;
		if (n <= new_len)
			moo_game(n - (before_len + 3 + k), (before_len - 2 - k) / 2, k - 1);
		else
			moo_game(n, new_len, k + 1);
	}
}

int main()
{
	fast;
	int n;

	cin >> n;
	moo_game(n, 3, 1);
	return (0);
}
