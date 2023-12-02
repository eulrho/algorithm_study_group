// 종이 접기 bj.1802
#include <iostream>
#include <string>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool check;

void divide(string paper, int size) {
    if (size <= 1) return ;
    for (int j=0; j<size/2; j++) {
        if (paper[j] == paper[size-1-j]) {
            cout << "NO" << '\n';
            check = true;
            break ;
        }
    }
    if (check == false) divide(paper, size / 2);
}

int main()
{
    fast;
    int t;
    string paper;

    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> paper;
        check = false;
        divide(paper, paper.size());
        if (check == false) cout << "YES" << '\n';
    }
    return (0);
}