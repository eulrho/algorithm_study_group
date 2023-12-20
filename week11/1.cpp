// 병든 나이트 bj.1783
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n, m;
bool stop = false;
// order : 1, 4, 2, 3
int dx[4] = {1, 1, 2, 2};
int dy[4] = {-2, 2, -1, 1};

long long four_orders()
{
    int y = n, x= 1;
    long long i;

    for (i = 0; i < 4; i++) {
        y += dy[i];
        x += dx[i];
        if (y > n || x > m){
            stop = true;
            break ;
        }
    }
    return (i);
}

long long greedy()
{
    long long count;

    if (n >= 3) {
        if (m <= 4)
            return (m);
        count = 1 + four_orders();
        if (stop) return (count);
        else {
            count += m - 7;
            return (count);
        }
    }
    else {
        if (n == 1) return (1);
        if (m <= 7)
            return ((m + 1) / 2);
        else return (4);
    }
}

int main()
{
    fast;
    cin >> n >> m;
    cout << greedy();
    return (0);
}