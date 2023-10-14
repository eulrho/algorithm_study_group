// 큐 2 bj.18258
#include <iostream>
#include <string>
#include <queue>

using namespace std;

void queue_command(string command, queue<int> &q)
{
    int num;

    if (command == "push")
    {
        cin >> num;
        q.push(num);
    }
    else if (command == "back")
    {
        if (q.empty())
            cout << "-1";
        else
            cout << q.back();
        cout << '\n';
    }
    else if (command == "front")
    {
        if (q.empty())
            cout << "-1";
        else
            cout << q.front();
        cout << '\n';
    }
    else if (command == "size")
        cout << q.size() << '\n';
    else if (command == "empty")
    {
        if (q.empty())
            cout << "1";
        else
            cout << "0";
        cout << '\n';
    }
    else if (command == "pop")
    {
        if (q.empty())
            cout << "-1";
        else
        {
            cout << q.front();
            q.pop();
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    string command;
    queue<int> q;

    cin >> N;
    while (--N >= 0)
    {
        cin >> command;
        queue_command(command, q);
    }
    return (0);
}