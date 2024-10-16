// 괄호의 값 bj.2504
#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int find_sum(string str, char target, int *idx)
{
	int res = 0;

	while (*idx < (int)str.size()) {
		if (str[*idx] == '(' || str[*idx] == '[') {
			char new_target = str[*idx];
			(*idx)++;
			int tmp = find_sum(str, new_target, idx);
			if (tmp == 0) return 0;
			res += tmp;
		}
		else if (target == '(' && str[*idx] == ')')
		{
		    if (res == 0) res = 1;
		    return res * 2;
		}
		else if (target == '[' && str[*idx] == ']')
		{
		    if (res == 0) res = 1;
		    return res * 3;
		}
		else return 0;
		(*idx)++;
	}
	if (target == '(' || target == '[') return 0;
	return res;
}

int main()
{
	fast;
	string str;
	cin >> str;

	int idx=0;
	cout << find_sum(str, '\0' , &idx);
	return 0;
}