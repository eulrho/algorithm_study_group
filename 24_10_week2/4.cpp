// 사분면 bj.1891
#include <iostream>
#include <string>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

typedef long long ll;

ll pos_x_left, pos_y_left, pos_x_right, pos_y_right;
string res;

void find_pos(string number, ll depth, ll y_left, ll y_right, ll x_left, ll x_right)
{
	if (depth == (int)number.length()) {
		pos_x_left = x_left;
		pos_x_right = x_right;
		pos_y_left = y_left;
		pos_y_right = y_right;
		return ;
	}
	if (x_left < x_right && y_left < y_right) {
		ll x_mid = (x_left + x_right) / 2;
		ll y_mid = (y_left + y_right) / 2;

		if (number[depth] == '2')
			find_pos(number, depth + 1, y_left, y_mid, x_left, x_mid);
		else if (number[depth] == '1')
			find_pos(number, depth + 1, y_left, y_mid, x_mid + 1, x_right);
		else if (number[depth] == '3')
			find_pos(number, depth + 1, y_mid + 1, y_right, x_left, x_mid);
		else
			find_pos(number, depth + 1, y_mid + 1, y_right, x_mid + 1, x_right);
		
	}
}

void find_destination(ll y_left, ll y_right, ll x_left, ll x_right)
{
	if (y_left == pos_y_left && y_right== pos_y_right && x_left == pos_x_left && x_right == pos_x_right) {
		return ;
	}
	if (x_left < x_right && y_left < y_right) {
		ll x_mid = (x_left + x_right) / 2;
		ll y_mid = (y_left + y_right) / 2;

		if (pos_y_right <= y_mid && pos_x_right <= x_mid) {
			res += '2';
			find_destination(y_left, y_mid, x_left, x_mid);
		}
		else if (pos_y_right <= y_mid && pos_x_left > x_mid) {
			res += '1';
			find_destination(y_left, y_mid, x_mid + 1, x_right);
		}
		else if (pos_y_left > y_mid && pos_x_right <= x_mid) {
			res += '3';
			find_destination(y_mid + 1, y_right, x_left, x_mid);
		}
		else {
			res += '4';
			find_destination(y_mid + 1, y_right, x_mid + 1, x_right);
		}
	}
}

int main()
{
	fast;
	int d;
	string number;
	ll x, y, max_len;

	cin >> d >> number >> x >> y;
	max_len = (ll)pow(2, d);
	find_pos(number, 0, 1, max_len, 1, max_len);
	pos_x_left += x;
	pos_y_left -= y;
	pos_x_right += x;
	pos_y_right -= y;
	if (pos_x_left <= 0 || pos_x_left > max_len || pos_y_left <= 0 || pos_y_left > max_len) {
		cout << -1;
		return 0;
	}
	find_destination(1, max_len, 1, max_len);
	cout << res;
	return 0;
}
