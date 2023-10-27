// 에디터 bj.1406
#include <iostream>
#include <string>
#include <list>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

using namespace std;

void initialize_set(list<char> &lst, string str, int len)
{
    for (int i=len-1; i>=0; i--)
        lst.push_back(str[i]);
    lst.push_back(1); // head
    lst.push_back(2); // tail
}

int main()
{
    fast;
    int test_case, i=0, len;
    char order, c;
    string str;
    list<char> lst;

    cin >> str >> test_case;
    len = str.size();
    initialize_set(lst, str, len);
     while (i < test_case)
    {
        cin >> order;
        switch (order) {
            case 'L' :
                if (len != 0 && lst.front() != 1)
                {
                    lst.push_back(lst.front());
                    lst.pop_front();
                }
                break ;
            case 'D' :
                if (len != 0 && lst.back() != 2)
                {
                    lst.push_front(lst.back());
                    lst.pop_back();
                }
                break ;
            case 'B' :
                if (len != 0 && lst.front() != 1)
                {
                    lst.pop_front();
                    len--;
                }
                break ;
            case 'P' :
                cin >> c;
                lst.push_front(c);
                len++;
                break ;
        }
        i++;
    }
    while (lst.front() != 1)
    {
        lst.push_front(lst.back());
        lst.pop_back();
    }
    for (int i=0; i< len; i++)
    {
        cout << lst.back();
        lst.pop_back();
    }
    return (0);
}