// 괄호의 값 bj.2504
#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int str_size;

int find_bracket_value(string str, int *idx, char target)
{
	int res = 0, tmp;
	char new_target;

	while (*idx < str_size) {
		if (target == '(' && str[*idx] == ')') {
			(*idx)++;
			if (!res) return (2);
			else return (res * 2);
		}
		else if (target == '[' && str[*idx] == ']') {
			(*idx)++;
			if (!res) return (3);
			else return (res * 3);
		}
		else if (str[*idx] == '(' || str[*idx] == '['){
			new_target = str[*idx];
			(*idx)++;
			tmp = find_bracket_value(str, idx, new_target);
			if (tmp == 0) return (0);
			else res += tmp;
		}
		else return (0);
	}
	if (target == '.') return (res);
	else return (0);
}

int main()
{
	fast;
	string str;
	int idx = 0;

	cin >> str;
	if (str.size() == 1) {
		cout << 0;
		return (0);
	}
	str_size = (int)str.size();
	cout << find_bracket_value(str, &idx, '.');
	return (0);
}