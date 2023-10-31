// 지뢰 찾기 bj.1996
#include <iostream>
#include <string>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

bool is_num(char c)
{
    return (c >= '0' && c <= '9');
}

using namespace std;
int main()
{
    int test_case;
    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    string str;
    cin >> test_case;
    vector<vector<char>> v(test_case,vector<char>(test_case,48));

    for (int i=0; i<test_case; i++)
    {
        cin >> str;
        for (int j=0; j<test_case; j++)
        {
            if (is_num(str[j])){
                v[i][j] = '*';
                for (int k = 0; k < 8 ; k++)
                {
                    if (i + dy[k] >= 0 && i + dy[k] < test_case && j + dx[k] >= 0 && j + dx[k] < test_case)
                    {
                         if (v[i + dy[k]][j + dx[k]] != '*' && v[i + dy[k]][j + dx[k]] != 'M')
                         {
                             v[i + dy[k]][j + dx[k]] = v[i + dy[k]][j + dx[k]] - '0' + str[j];
                             if (v[i + dy[k]][j + dx[k]] > '9')
                                 v[i + dy[k]][j + dx[k]] = 'M';
                         }
                    }
                }
            }
        }
    }
    for (auto f : v)
    {
        for (auto s : f)
            cout << s;
        cout << '\n';
    }
    return (0);
}