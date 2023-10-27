// 키로거 bj.5397
#include <iostream>
#include <string>
#include <list>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

using namespace std;

void print_list(list<char> &lst, int len)
{
    while (lst.front() != 1)
    {
        lst.push_front(lst.back());
        lst.pop_back();
    }
    lst.pop_front();
    for (int i=0; i< len; i++)
    {
        cout << lst.front();
        lst.pop_front();
    }
    cout << '\n';
}

int main()
{
    fast;
    int test_case, len, max;
    string str;
    list<char> lst;

    cin >> test_case;
    for (int i=0; i<test_case; i++)
    {
        cin >> str;
        len = 0;
        max = str.size();
        lst.push_back(1); // head
        for (int j=0; j<max; j++)
        {
            switch (str[j]) {
                case '<':
                    if (len != 0 && lst.back() != 1)
                    {
                        lst.push_front(lst.back());
                        lst.pop_back();
                    }
                    break ;
                case '>':
                    if (len != 0 && lst.front() != 1)
                    {
                        lst.push_back(lst.front());
                        lst.pop_front();
                    }
                    break ;
                case '-':
                    if (len != 0 && lst.back() != 1)
                    {
                        lst.pop_back();
                        len--;
                    }
                    break ;
                default :
                    lst.push_back(str[j]);
                    len++;
            }
        }
        print_list(lst, len);
    }
    return (0);
}