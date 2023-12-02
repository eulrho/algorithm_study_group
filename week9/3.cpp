// 게임 bj.1072
#include <iostream>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int check(int x, int y, int mid)
{
    double origin_z = (double)y * 100 / x;
    double new_z = (double)(y + mid) * 100 / (x + mid);
    if ((int)new_z > (int)origin_z) return (1);
    else return (0);
}

int binary_search(int x, int y, int min, int max)
{
    int left, right, mid;

    left = min, right = max;
    while (left <= right) {
        mid = (left + right) / 2;
        if (check(x, y, mid)) {
            if (!check(x, y, mid - 1)) return (mid);
            right = mid - 1;
        }
        else left = mid + 1;
    }
    return (-1);
}

int main()
{
    int x, y;

    cin >> x >> y;
    cout << binary_search(x, y, 0, x);
    return (0);
}