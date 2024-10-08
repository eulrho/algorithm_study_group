// 하노이 탑 bj.1914
#include <iostream>
#include <cmath>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void hanoi(int n, int start, int dest, int middle)
{
	if (n != 1)
		hanoi(n - 1, start, middle, dest);
	cout << start << ' ' << dest << '\n';
	if (n != 1)
		hanoi(n - 1, middle, dest, start);
}

string bigInt(int n)
{
	string res = to_string((int)pow(2, 20));
	for (int i=1; i<=(n-20); i++) {
		int idx = (int)res.size(), tmp = 0;

		while (--idx >= 0) {
			tmp += (res[idx] - '0') * 2;
			if (tmp <= 9) {
				res[idx] = tmp + '0';
				tmp = 0;
			}
			else {
				res[idx] = (tmp % 10) + '0';
				tmp /= 10;
			}
		}
		if (tmp != 0) res = to_string(tmp) + res;
	}
	res[(int)res.size()-1]--;
	return res;
}

int main()
{
	fast;
	int n;

	cin >> n;
	if (n > 20) {
		cout << bigInt(n);
		return 0;
	}
	else cout << (int)pow(2, n) - 1;
	cout << '\n';
	hanoi(n, 1, 3, 2);
	return 0;
}