// 다이어트 bj.1484
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	long long g, left=1, right=1;
	bool flag = false;
	long tmp[50001];

	cin >> g;
	for (long i=1; i<=50000; i++)
		tmp[i] = i*i;
	while (right <= 50000) {
		if ((right + left) * (right - left) == g) {
			flag = true;
			cout << right << '\n';
			right++;
			left++;
		}
		else if ((right + left) * (right - left) > g)
			left++;
		else
			right++;
	}
	if (!flag) cout << -1;
	return 0;
}