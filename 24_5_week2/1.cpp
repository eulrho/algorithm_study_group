// 줄 세우기 bj.2605
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int line[102];

void re_setting(int num, int idx)
{
	for (int i=idx-1; i>=idx-num; i--) {
		line[i + 1] = line[i];
	}
	line[idx-num] = idx;
}

int main()
{
	fast;
	int n, num;

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> num;
		re_setting(num, i);
	}
	for (int i=1; i<=n; i++) cout << line[i] << ' ';
	return (0);
}