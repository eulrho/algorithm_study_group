// 별 찍기 - 10 bj.2447
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void print_star(int size, int y, int x)
{
    if ((y / size) % 3 == 1 && (x / size) % 3 == 1) cout << ' ';
    else {
        if (size / 3 == 0) cout << '*';
        else print_star(size/3, y, x);
    }
}

void star(int size)
{
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            print_star(size, i, j);
        }
        cout << '\n';
    }
}

int main()
{
    fast;
    int n;

    cin >> n;
    star(n);
    return (0);
}