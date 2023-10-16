// 나는야 포켓몬 마스터 이다솜 bj.1620
#include <iostream>
#include <string>
#include <utility>
#include <unordered_map>

using namespace std;

bool is_disit(string str)
{
    return (str[0] >= '0' && str[0] <= '9');
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unordered_map<string, string> hash_s_i;
    unordered_map<string, string> hash_i_s;
    int N, M;
    string poketmon, q;

    cin >> N >> M;
    for (int i=1; i<=N; i++)
    {
        cin >> poketmon;
        hash_s_i.insert(make_pair(poketmon, to_string(i)));
        hash_i_s.insert(make_pair(to_string(i), poketmon));
    }
    for (int i=1; i<=M; i++)
    {
        cin >> q;
        if (is_disit(q))
            cout << hash_i_s[q] << '\n';
        else
            cout << hash_s_i[q] << '\n';
    }
    return (0);
}