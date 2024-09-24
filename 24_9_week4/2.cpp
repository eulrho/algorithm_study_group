// 리모컨 bj.1107
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int min_cnt;

bool is_broken(vector<char> &buttons, string number)
{
	for (int i=0; i<(int)number.length(); i++) {
		if (find(buttons.begin(), buttons.end(), number[i]) != buttons.end())
			return true;
	}
	return false;
}

void find_number_up(int n, vector<char> &buttons, int cnt)
{
	while(true) {
		if (!is_broken(buttons, to_string(n))) {
			int tmp = min((int)to_string(n).length(), abs(n - 100));
			min_cnt = min(tmp + cnt, min_cnt);
			return ;
		}
		if (n == 999999) return ;
		n++;
		cnt++;
	}
}

void find_number_down(int n, vector<char> &buttons, int cnt)
{
	while(true) {
		if (!is_broken(buttons, to_string(n))) {
			int tmp = min((int)to_string(n).length(), abs(n - 100));
			min_cnt = min(tmp + cnt, min_cnt);
			return ;
		}
		if (n == 0) return ;
		n--;
		cnt++;
	}
}

int main()
{
	fast;
	int n, m;
	char button;
	cin >> n >> m;

	vector<char> buttons;
	for (int i=0; i<m; i++) {
		cin >> button;
		buttons.push_back(button);
	}
	sort(buttons.begin(), buttons.end());
	min_cnt = abs(n - 100);
	if (m == 10) {
		cout << min_cnt;
		return 0;
	}
	find_number_up(n, buttons, 0);
	find_number_down(n, buttons, 0);
	cout << min_cnt;
	return (0);
}