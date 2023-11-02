// 단지번호붙이기 bj.2667
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <utility>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

stack<pair<int, int>> st;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

int surr(vector<string> v, vector<vector<bool>> &visited, int N , int i, int j)
{
    int cnt = 0;

    for (int k=0; k<4; k++) {
        if (i + dy[k] >= 0 && i + dy[k] < N && j + dx[k] >= 0 && j + dx[k] < N) {
            if (visited[i + dy[k]][j + dx[k]] == false && v[i + dy[k]][j + dx[k]] == '1') {
                st.push(make_pair(i + dy[k], j + dx[k]));
                cnt++;
            }
        }
    }
    return (cnt);
}

int search(vector<string> v, vector<vector<bool>> &visited, int N , int i, int j)
{
    int cnt = 0, temp;

    st.push(make_pair(i, j));
    while (st.size())
    {
        if (visited[st.top().first][st.top().second] == false)
        {
            visited[st.top().first][st.top().second] = true;
            cnt++;
        }
        temp = surr(v, visited, N , st.top().first, st.top().second);
        if (temp == 0)
            st.pop();
    }
    return (cnt);
}

vector<int> count(vector<string> v, int N)
{
    vector<int> res;
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (v[i][j] == '1' && visited[i][j] == false) {
                res.push_back(search(v, visited, N , i, j));
            }
        }
    }
    return (res);
}

int main()
{
    fast;
    int N;
    string str;
    vector<string> nodes;
    vector<int> res;

    cin >> N;
    for (int i=0; i<N; i++)
    {
        cin >> str;
        nodes.push_back(str);
    }
    res = count(nodes, N);
    sort(res.begin(), res.end());
    cout << res.size() << '\n';
    for (auto r : res)
        cout << r << '\n';
    return (0);
}