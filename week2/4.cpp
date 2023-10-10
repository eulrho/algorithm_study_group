// 스택2 bj.28278
#include <iostream>
#include <stack>

using namespace std;

void stack_command(int command, stack<int> &st)
{
    int num;

    if (command == 1)
    {
        cin >> num;
        st.push(num);
    }
    else if (command == 5)
    {
        if (st.empty())
            cout << "-1";
        else
            cout << st.top();
        cout << '\n';
    }
    else if (command == 3)
        cout << st.size() << '\n';
    else if (command == 4)
        cout << st.empty() << '\n';
    else if (command == 2)
    {
        if (!st.empty())
        {
            cout << st.top();
            st.pop();
        }
        else
            cout << "-1";
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, command;
    stack<int> st;

    cin >> N;
    while (--N >= 0)
    {
        cin >> command;
        stack_command(command, st);
    }
    return (0);
}
