// Z bj.1074
#include <iostream>
#include <cmath>
using namespace std;

int cnt = 0;
int c, r, n;
bool ch = false;

void divide(int size, int y_left, int x_left)
{
    if (ch == true) return ;
    if (y_left + size - 1 < r || x_left + size - 1 < c) cnt += size * size;
    else if (size == 2) {
        for (int i=0; i<2; i++) {
            for (int j=0; j<2; j++) {
                if (y_left + i == r && x_left + j == c) {
                    ch = true;
                    return ;
                }
                else cnt++;
            }
        }
    }
    else {
        for (int i=0; i<2; i++) {
            for (int j=0; j<2; j++) {
                divide(size / 2, y_left+size*(i)/2, x_left+size*(j)/2);
            }
        }
    }
}

int main()
{
    cin >> n >> r >> c;
    divide(pow(2, n), 0, 0);
    cout << cnt;
    return (0);
}