// 섬의 개수 bj.4963
#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

stack<pair<int, int>> st;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int surr(vector<vector<int>> v, vector<vector<bool>> &visited, int h, int w, int i, int j)
{
    int cnt = 0;

    for (int k=0; k<8; k++) {
        if (i + dy[k] >= 0 && i + dy[k] < h && j + dx[k] >= 0 && j + dx[k] < w) {
            if (visited[i + dy[k]][j + dx[k]] == false && v[i + dy[k]][j + dx[k]] == 1) {
                st.push(make_pair(i + dy[k], j + dx[k]));
                cnt++;
            }
        }
    }
    return (cnt);
}

int search(vector<vector<int>> v, vector<vector<bool>> &visited, int h, int w, int i, int j)
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
        temp = surr(v, visited, h, w, st.top().first, st.top().second);
        if (temp == 0)
            st.pop();
    }
    return (cnt);
}

vector<int> count(vector<vector<int>> v, int h, int w)
{
    vector<int> res;
    vector<vector<bool>> visited(h, vector<bool>(w, false));

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (v[i][j] == 1 && visited[i][j] == false) {
                res.push_back(search(v, visited, h, w, i, j));
            }
        }
    }
    return (res);
}

void insert(vector<vector<int>> &v, int h, int w)
{
    int n;

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cin >> n;
            v[i].push_back(n);
        }
    }
}

int main()
{
    fast;
    int w, h;
    vector<int> res;

    while (1)
    {
        cin >> w >> h;
        if (w == 0 && h == 0)
            break ;
        vector<vector<int>> nodes(h);
        insert(nodes, h, w);
        res.push_back(count(nodes, h, w).size());
    }
    for (auto r : res)
        cout << r << '\n';
    return (0);
}