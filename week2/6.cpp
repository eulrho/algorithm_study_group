// 스택 수열 bj.1874
#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, number;
    queue<int> seq;
    stack<int> st;
    vector<char> result;

    cin >> N;
    for (int i=0; i<N; i++)
    {
        cin >> number;
        seq.push(number);
    }
    for (int i=1; i<=N; i++)
    {
        st.push(i);
        result.push_back('+');
        while ((!st.empty() && !seq.empty()) && seq.front() == st.top())
        {
            st.pop();
            seq.pop();
            result.push_back('-');
        }
    }
    if (st.empty())
    {
        for (auto r : result)
            cout << r << '\n';
    }
    else
        cout << "NO";
    return (0);
}