// 괄호 bj.9012
#include <iostream>
#include <stack>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	stack<int> st;
	string str;
	int t, end_flag;

	cin >> t;
	for (int i=0; i<t; i++) {
		cin >> str;
		end_flag = 1;
		st = stack<int>();
		for (int j=0; j<str.size(); j++) {
			if (str[j] == '(') st.push(1);
			else if (str[j] == ')') {
				if (st.empty()) {
					end_flag = 0;
					break ;
				}
				else st.pop();
			}
		}
		if (end_flag == 0 || !st.empty()) cout << "NO\n";
		else cout << "YES\n";
	}
	return (0);
}
