// 바이러스 bj.2606
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void sort_v(vector<vector<int>> &v, int N)
{
    for (int i=1; i<=N; i++)
        sort(v[i].begin(), v[i].end());
}

int dfs(vector<vector<int>> v, int N)
{
    vector<bool> visited(N + 1, false);
    stack<int> st;
    int i, cnt=0;

    st.push(1);
    while (st.size())
    {
        if (visited[st.top()] == false)
        {
            visited[st.top()] = true;
            cnt++;
        }
        i=0;
        while (i < v[st.top()].size() && visited[v[st.top()][i]] == true)
            i++;
        if (i == v[st.top()].size())
            st.pop();
        else
            st.push(v[st.top()][i]);
    }
    return (cnt);
}

int main()
{
    int computer, node_n, node_a, node_b;
    cin >> computer >> node_n;
    vector<vector<int>> nodes(computer + 1);

    for (int i=0; i<node_n; i++)
    {
        cin >> node_a >> node_b;
        nodes[node_a].push_back(node_b);
        nodes[node_b].push_back(node_a);
    }
    sort_v(nodes, computer);
    cout << dfs(nodes, computer) - 1;
    return (0);
}