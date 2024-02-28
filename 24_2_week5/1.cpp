// 사분면 bj.1891
#include <iostream>
#include <string>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int d;
long long x, y;
string number;
long long target_x, target_y;

void find_new_position(long long y_min, long long y_max, long long x_min, long long x_max, string quadrant, string &res)
{
	if (y_min == y_max && x_min == x_max && y_min == target_y && x_min == target_x) {
		res = quadrant;
		return ;
	}
	if (y_min == y_max || x_min == x_max) return ;
	if (target_y <= (y_min + y_max) / 2 && target_x <= (x_min + x_max) / 2)
		find_new_position(y_min, (y_min + y_max) / 2, x_min, (x_min + x_max) / 2, quadrant + '2', res);
	if (target_y <= (y_min + y_max) / 2 && target_x > (x_min + x_max) / 2)
		find_new_position(y_min, (y_min + y_max) / 2, (x_min + x_max) / 2 + 1, x_max, quadrant + '1', res);
	if (target_y > (y_min + y_max) / 2 && target_x <= (x_min + x_max) / 2)
		find_new_position((y_min + y_max) / 2 + 1, y_max, x_min, (x_min + x_max) / 2, quadrant + '3', res);
	if (target_y > (y_min + y_max) / 2 && target_x > (x_min + x_max) / 2)
		find_new_position((y_min + y_max) / 2 + 1, y_max, (x_min + x_max) / 2 + 1, x_max, quadrant + '4', res);
}

void find_target_position(long long y_min, long long y_max, long long x_min, long long x_max, int size)
{
	if (y_min == y_max || x_min == x_max) {
		target_y = y_min;
		target_x = x_min;
		return ;
	}
	if (number[size] == '2')
		find_target_position(y_min, (y_min + y_max) / 2, x_min, (x_min + x_max) / 2, size + 1);
	else if (number[size] == '1')
		find_target_position(y_min, (y_min + y_max) / 2, (x_min + x_max) / 2 + 1, x_max, size + 1);
	else if (number[size] == '3')
		find_target_position((y_min + y_max) / 2 + 1, y_max, x_min, (x_min + x_max) / 2, size + 1);
	else if (number[size] == '4')
		find_target_position((y_min + y_max) / 2 + 1, y_max, (x_min + x_max) / 2 + 1, x_max, size + 1);
}

int main()
{
	fast;
	string res="";

	cin >> d >> number >> x >> y;
	find_target_position(1, (long long)pow(2, d), 1, (long long)pow(2, d), 0);
	target_y -= y;
	target_x += x;
	find_new_position(1, (long long)pow(2, d), 1, (long long)pow(2, d), "", res);
	if (res == "") cout << "-1";
	else cout << res;
	return (0);
}