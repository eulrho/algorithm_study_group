// 덱 bj.10866
#include <iostream>
#include <string>
#include <deque>

using namespace std;

void deque_command(string command, deque<int> &v_deq)
{
    int num;

    if (command == "push_front")
    {
        cin >> num;
        v_deq.push_front(num);
    }
    else if (command == "push_back")
    {
        cin >> num;
        v_deq.push_back(num);
    }
    else if (command == "front")
    {
        if (v_deq.empty()) cout << "-1\n";
        else cout << v_deq.front() << '\n';
    }
    else if (command == "back")
    {
        if (v_deq.empty()) cout << "-1\n";
        else cout << v_deq.back() << '\n';
    }
    else if (command == "size")
        cout << v_deq.size() << '\n';
    else if (command == "empty")
        cout << v_deq.empty() << '\n';
    else if (command == "pop_front")
    {
        if (!v_deq.empty())
        {
            cout << v_deq.front() << '\n';
            v_deq.pop_front();
        }
        else cout << "-1\n";
    }
    else if (command == "pop_back")
    {
        if (!v_deq.empty())
        {
            cout << v_deq.back() << '\n';
            v_deq.pop_back();
        }
        else cout << "-1\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    string command;
    deque<int> v_deq;

    cin >> N;
    while (--N >= 0)
    {
        cin >> command;
        deque_command(command, v_deq);
    }
    return (0);
}