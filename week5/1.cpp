// DFS와 BFS bj.1260
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void sort_v(vector<vector<int>> &v, int N)
{
    for (int i=1; i<=N; i++)
        sort(v[i].begin(), v[i].end());
}

void bfs(vector<vector<int>> v, int N, int start)
{
    vector<bool> visited(N + 1, false);
    queue<int> q;
    int cnt=0;

    q.push(start);
    while (q.size())
    {
        if (visited[q.front()] == false)
        {
            visited[q.front()] = true;
            cout << q.front();
            if (cnt < N)
                cout << ' ';
            cnt++;
        }
        for (int i=0; i<v[q.front()].size(); i++)
            if (visited[v[q.front()][i]] == false) q.push(v[q.front()][i]);
        q.pop();
    }
}

void dfs(vector<vector<int>> v, int N, int start)
{
    vector<bool> visited(N + 1, false);
    stack<int> st;
    int i, cnt=0;

    st.push(start);
    while (st.size())
    {
        if (visited[st.top()] == false)
        {
            visited[st.top()] = true;
            cout << st.top();
            if (cnt < N)
                cout << ' ';
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
}

int main()
{
    fast;
    int N, M, V, node_a, node_b;
    cin >> N >> M >> V;
    vector<vector<int>> nodes(N + 1);

    for (int i=0; i<M; i++)
    {
        cin >> node_a >> node_b;
        nodes[node_a].push_back(node_b);
        nodes[node_b].push_back(node_a);
    }
    sort_v(nodes, N);
    dfs(nodes, N, V);
    cout << '\n';
    bfs(nodes, N, V);
    return (0);
}