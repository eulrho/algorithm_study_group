// 균형잡힌 세상 bj.4949
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool is_balace(string str)
{
    stack<char> st;
    int i = 0;

    while (str[i] != '.')
    {
        if (str[i] == '(' || str[i] == '[')
            st.push(str[i]);
        else if ((str[i] == ')' || str[i] == ']'))
        {
            if (!st.empty())
            {
                if ((str[i] == ')' && st.top() == '(') || (str[i] == ']' && st.top() == '['))
                    st.pop();
                else return (false);
            }
            else return (false);
        }
        i++;
    }
    if (st.empty()) return (true);
    else return (false);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string str;

    while (1)
    {
        getline(cin, str);
        if (str == ".") break;
        if (is_balace(str))
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return (0);
}