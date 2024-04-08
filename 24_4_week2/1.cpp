// 스네이크버드 bj.16435
#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int h[10000];

int main()
{
	fast;
	int n, l;

	cin >> n >> l;
	for (int i = 0; i < n; i++)
		cin >> h[i];
	sort(h, h + n);
	for (int i = 0; i < n; i++) {
		if (h[i] <= l) l++;
		else break;
	}
	cout << l;
	return (0);
}