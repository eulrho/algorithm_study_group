// 별 찍기 - 22 bj.10997
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, w, h, l, r;

	cin >> n;
	if (n == 1) {
		cout << "*";
		return (0);
	}
	w = 1 + 4 * (n - 1);
	h = 3 + 4 * (n - 1);
	l = 0, r = w + 1;
	for (int i=0; i<h; i++) {
		if (i < h / 2) {
			if (i % 2 == 0) {
				for (int j=0; j<w; j++) {
					if (j >= l && j <= r) cout << '*';
					else {
						if (j % 2 == 0) cout << '*';
						else cout << ' ';
					}
				}
			}
			else {
				for (int j=0; j<w; j++) {
					if (j > l && j < r) {
						if (r < w) cout << ' ';
					}
					else {
						if (j % 2 == 0) cout << '*';
						else cout << ' ';
					}
				}
				l += 2; r -= 2;
			}
		}
		else if (i == h / 2) {
			for (int j=0; j<w; j++) {
				if (j % 2 == 0) cout << '*';
				else cout << ' ';
			}
			l = w / 2; r = w / 2;
		}
		else {
			if (i % 2 == 0) {
				for (int j=0; j<w; j++) {
					if (j >= l && j <= r) cout << '*';
					else {
						if (j % 2 == 0) cout << '*';
						else cout << ' ';
					}
				}
				l -= 2; r += 2;
			}
			else {
				for (int j=0; j<w; j++) {
					if (j > l && j < r) cout << ' ';
					else {
						if (j % 2 == 0) cout << '*';
						else cout << ' ';
					}
				}
			}
		}
		if (i < h - 1)
			cout << '\n';
	}
	return (0);
}