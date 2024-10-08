// 좀비 떼가 기관총 진지에도 오다니 bj.19644
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int zombie[3000001];
int damage_sum[3000001];

int main()
{
	fast;
	int l, ml, mk, c;
	cin >> l >> ml >> mk >> c;

	for (int i=1; i<=l; i++) cin >> zombie[i];
	for (int i=1; i<=l; i++) {
		int damage = damage_sum[i - 1] - damage_sum[max(0, i - ml)];
		if (zombie[i] <= damage + mk) {
			damage_sum[i] = damage_sum[i - 1] + mk;
			continue ;
		}
		if (c == 0) {
			cout << "NO";
			return 0;
		}
		c--;
		damage_sum[i] = damage_sum[i - 1];
	}
	cout << "YES";
	return 0;
}