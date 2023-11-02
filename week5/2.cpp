// 바닥 장식 bj.1388
#include <iostream>
#include <vector>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int count(vector<string> v, int N, int M) {
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    int k, cnt=0;

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            k = 0;
            if (v[i][j] == '-' && visited[i][j] == false) {
                cnt++;
                while (j + k < M && v[i][j + k] == '-')
                {
                    visited[i][j + k] = true;
                    k++;
                }
                j += k - 1;
            }
            else if (v[i][j] == '|' && visited[i][j] == false) {
                cnt++;
                while (i + k < N && v[i + k][j] == '|')
                {
                    visited[i + k][j] = true;
                    k++;
                }
            }
        }
    }
    return (cnt);
}

int main()
{
    fast;
    int N, M;
    string str;
    cin >> N >> M;
    vector<string> nodes;

    for (int i=0; i<N; i++)
    {
        cin >> str;
        nodes.push_back(str);
    }
    cout << count(nodes, N, M);
    return (0);
}