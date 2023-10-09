// 단어순서 뒤집기 bj.12605
#include <iostream>
#include <stack>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int N, size;
    string input_str, word;
    stack<string> st;

    cin >> N;
    cin.ignore();
    for (int i=0; i<N; i++)
    {
        getline(cin, input_str);
        stringstream ss(input_str);
        while (getline(ss, word, ' '))
            st.push(word);
        size = st.size();
        cout << "Case #" << i + 1 << ": ";
        while (--size >= 0)
        {
            cout << st.top();
            st.pop();
            if (size == 0)
                cout << '\n';
            else
                cout << ' ';
        }
    }
    return (0);
}