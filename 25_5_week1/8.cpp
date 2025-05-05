// 괄호 짝 맞추기
#include <iostream>
#include <string>
#include <stack>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool solution(string s) {
	stack<char> st;
	for (int i=0; i<(int)s.size(); i++) {
		if (s[i] == '(') st.push('(');
		else {
			if (st.top() == '(') st.pop();
			else return false;
		}
	}
	if (!st.empty()) return false;
	return true;
}

int main()
{
	fast;
//	string s = "(())()";
	string s = "((())()";
	cout << (solution(s) ? "true" : "false");
	return (0);
}