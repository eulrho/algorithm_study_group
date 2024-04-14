// 레벨 햄버거 bj.16974
#include <iostream>
using namespace std;
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef unsigned long long u_ll;

u_ll find_cnt_patty(u_ll x, u_ll layer, u_ll patty, int level)
{
	if (layer / 2 >= x) {
		if (x >= 2)
			return (find_cnt_patty(x - 1, (layer - 3) / 2, (patty - 1) / 2, level - 1));
		else return (0);
	}
	else if (layer / 2 + 1 == x)
		return ((patty - 1) / 2 + 1);
	else if (x > layer - level)
		return (patty);
	else
		return ((patty - 1) / 2 + 1 + find_cnt_patty(x - 2 - (layer - 3) / 2, (layer - 3) / 2, (patty - 1) / 2, level - 1));
}

int main()
{
	fast;
	int n;
	u_ll x, layer = 1, patty=1;

	cin >> n >> x;
	for (int i=1; i<=n; i++) {
		layer = layer * 2 + 3;
		patty = patty * 2 + 1;
	}
	cout << find_cnt_patty(x, layer, patty, n);
	return (0);
}
