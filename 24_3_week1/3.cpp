// 잃어버린 괄호 bj.1541
#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void draw_parentheses(string &str)
{
	int min_flag=-1, plu_flag=0, end;

	for (int i=0; i<(int)str.size(); i++) {
		if (min_flag != -1 && plu_flag == 1 && (str[i] == '-' || i == (int)str.size() - 1)) {
			if (str[i] == '-') end = i;
			else end = i + 1;
			str.insert(end, ")");
			str.insert(min_flag, "(");
			plu_flag = 0;
			min_flag = -1;
		}
		if (str[i] == '-')
			min_flag = i+1;
		if (min_flag != -1 && str[i] == '+')
			plu_flag = 1;
	}
}

bool is_num(char c)
{
	return (c >= '0' && c <= '9');
}

void add_or_sub(string str, int *i, char *sign, int *result)
{
	int start;

	start = *i;
	while (is_num(str[*i]))
		(*i)++;
	if (start != *i) {
		if (*sign == '+')
			*result += stoi(str.substr(start, *i));
		else
			*result -= stoi(str.substr(start, *i));
		(*i)--;
	}
	if (str[*i] == '-') *sign = '-';
	else *sign = '+';
}

int calculate(string str)
{
	int size = (int)str.size(), i=0, result=0, temp;
	char sign = '+', temp_sign;

	while (i < size) {
		add_or_sub(str, &i, &sign, &result);
		if (str[i] == '(') {
			i++;
			temp=0;
			temp_sign='+';
			while (str[i] != ')') {
				add_or_sub(str, &i, &temp_sign, &temp);
				i++;
			}
			result -= temp;
		}
		i++;
	}
	return (result);
}

int main()
{
	fast;
	string str;

	cin >> str;
	draw_parentheses(str);
	cout << calculate(str);
	return (0);
}