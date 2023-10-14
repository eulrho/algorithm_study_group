// 식당 메뉴 bj.26043
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

void print_vector(vector<int> v)
{
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++)
        cout << v[i] << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, type, stu_n, men_n;
    queue<pair<int, int>> s;
    vector<vector<int>> result(3);

    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> type;
        switch (type) {
            case 1:
                cin >> stu_n >> men_n;
                s.push(make_pair(stu_n, men_n));
                break ;
            case 2:
                cin >> men_n;
                if (!s.empty())
                {
                    if (s.front().second == men_n)
                        result[0].push_back(s.front().first);
                    else
                        result[1].push_back(s.front().first);
                    s.pop();
                }
                break ;
        }
    }
    while (!s.empty())
    {
        result[2].push_back(s.front().first);
        s.pop();
    }
    for (int i=0; i<3; i++)
    {
        if (!result[i].empty())
            print_vector(result[i]);
        else
            cout << "None";
        cout << '\n';
    }
    return (0);
}