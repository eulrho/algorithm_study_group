// FBI bj.2857
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name;
    string res = "";

    for (int i=1; i<=5; i++)
    {
        cin >> name;
        for (int j=0; j<name.size()-2; j++)
        {
            if (name[j] == 'F' && (name[j + 1] == 'B' && name[j + 2] == 'I'))
            {
                res += (i + '0');
                break ;
            }
        }
    }
    if (res.size() == 0)
        cout << "HE GOT AWAY!";
    else
    {
        for (int i=0; i<res.size(); i++)
        {
            cout << res[i];
            if (i != res.size() - 1)
                cout << ' ';
        }
    }
    return (0);
}