// 쿼드트리 bj.1992
#include <iostream>
#include <string>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n;

string quad_tree(string *number, int y_left, int x_left, int depth)
{
	int tmp = (int)pow(2, depth);
	int y_right = n / tmp + y_left - 1;
	int x_right = n / tmp + x_left - 1;
	if (y_right - y_left == 0) {
		string res;
		char front = '\0';
		bool flag = true;
		for (int i=y_left; i<=y_right; i++) {
			for (int j=x_left; j<=x_right; j++) {
				if (front && front != number[i][j]) flag = false;
				res += number[i][j];
				front = number[i][j];
			}
		}

		if (flag) return string(1, front);
		return '(' + res + ')';
	}

	int y[2] = {y_left, (y_left + y_right) / 2 + 1}, x[2] = {x_left, (x_left + x_right) / 2 + 1};
	string res, front, str_tmp;
	bool flag = true;
	for (int i=0; i<2; i++) {
		for (int j=0; j<2; j++) {
			str_tmp = quad_tree(number, y[i], x[j], depth + 1);
			if (!front.empty() && (str_tmp.size() != 1 || front != str_tmp)) flag = false;
			res += str_tmp;
			front = str_tmp;
		}
	}
	
	if (flag) return front;
	return '(' + res + ')';
}

int main()
{
	fast;
	cin >> n;

	string number[n];
	for (int i=0; i<n; i++) cin >> number[i];

	if (n == 1) {
		cout << number[0];
		return 0;
	}
	cout << quad_tree(number, 0, 0, 0);
	return 0;
}