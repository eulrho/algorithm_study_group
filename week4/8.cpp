// 좀비 떼가 기관총 진지에도 오다니 bj.19644
#include <iostream>
#include <list>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int L, ml, mk, c, z, flag = 1, cnt=0;
    list<int> lst;

    cin >> L >> ml >> mk >> c;
    for (int i=1; i<=L; i++)
    {
        cin >> z;
        if (cnt > 0 && lst.front() <= i - ml)
        {
            lst.pop_front();
            cnt--;
        }
        if (i <= ml)
            z -= mk*(i - cnt);
        else
            z -= mk*(i - (i - ml) - cnt);
        if (z <= 0)
            continue ;
        else if (c > 0)
        {
            c--;
            lst.push_back(i);
            cnt++;
        }
        else
            flag = 0;
    }
    if (flag == 1)
        cout << "YES";
    else
        cout << "NO";
    return (0);
}