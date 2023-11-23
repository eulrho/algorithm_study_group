// 색종이 만들기 bj.2630
#include <iostream>
using namespace std;

bool is_full(int paper[][128], int *blue, int *white, int y_left, int y_right, int x_left, int x_right)
{
    bool b = false, w = false;

    for (int i=y_left; i<=y_right; i++) {
        for (int j=x_left; j<=x_right; j++) {
            if (w == false && paper[i][j] == 1) b = true;
            else if (b == false && paper[i][j] == 0) w = true;
            else return (false);
        }
    }
    if (b == true) (*blue)++;
    else (*white)++;
    return (true);
}

void divide(int paper[][128], int *blue, int *white, int y_left, int y_right, int x_left, int x_right)
{
    int y_mid, x_mid;

    if (is_full(paper, blue, white, y_left, y_right, x_left, x_right) == true)
        return ;
    if (y_left < y_right && x_left < x_right) {
        y_mid = (y_left + y_right) / 2;
        x_mid = (x_left + x_right) / 2;
        divide(paper, blue, white, y_left, y_mid, x_left, x_mid);
        divide(paper, blue, white, y_left, y_mid, x_mid+1, x_right);
        divide(paper, blue, white, y_mid+1, y_right, x_left, x_mid);
        divide(paper, blue, white, y_mid+1, y_right, x_mid+1, x_right);
    }
}

int main()
{
    int n, white=0, blue=0;
    int paper[128][128];

    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) cin >> paper[i][j];
    }
    divide(paper, &blue, &white, 0, n-1, 0, n-1);
    cout << white << '\n' << blue;
    return (0);
}