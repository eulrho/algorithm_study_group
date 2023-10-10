// 스택 bj.10828
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isempty(vector<int> v)
{
    return (v.size() == 0);
}

void stack_command(string command, vector<int> &v_stack)
{
    int num;

    if (command == "push")
    {
        cin >> num;
        v_stack.push_back(num);
    }
    else if (command == "top")
    {
        if (isempty(v_stack) == true)
            cout << "-1";
        else
            cout << v_stack.back();
        cout << '\n';
    }
    else if (command == "size")
        cout << v_stack.size() << '\n';
    else if (command == "empty")
    {
        if (isempty(v_stack) == true)
            cout << "1";
        else
            cout << "0";
        cout << '\n';
    }
    else if (command == "pop")
    {
        if (isempty(v_stack) == false)
        {
            cout << v_stack.back();
            v_stack.pop_back();
        }
        else
            cout << "-1";
        cout << '\n';
    }
}

int main() {
    int N;
    string command;
    vector<int> v_stack;

    cin >> N;
    while (--N >= 0)
    {
        cin >> command;
        stack_command(command, v_stack);
    }
    return (0);
}
