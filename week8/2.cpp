// 쿼드트리 bj.1992
#include <iostream>
#include <string>
using namespace std;

int is_full(string video[], int y_left, int y_right, int x_left, int x_right)
{
    bool black = false, white = false;

    for (int i=y_left; i<=y_right; i++) {
        for (int j=x_left; j<=x_right; j++) {
            if (white == false && video[i][j] == '1') black = true;
            else if (black == false && video[i][j] == '0') white = true;
            else return (-1);
        }
    }
    if (black == true) return (1);
    return (0);
}

void divide(string video[], int y_left, int y_right, int x_left, int x_right)
{
    int y_mid, x_mid, temp;

    temp = is_full(video, y_left, y_right, x_left, x_right);
    if (temp != -1)
    {
        cout << temp;
        return ;
    }
    if (y_left < y_right && x_left < x_right) {
        cout << '(';
        y_mid = (y_left + y_right) / 2;
        x_mid = (x_left + x_right) / 2;
        divide(video, y_left, y_mid, x_left, x_mid);
        divide(video, y_left, y_mid, x_mid+1, x_right);
        divide(video, y_mid+1, y_right, x_left, x_mid);
        divide(video, y_mid+1, y_right, x_mid+1, x_right);
        cout << ')';
    }
}

int main()
{
    int n;
    string video[64];

    cin >> n;
    for (int i=0; i<n; i++)
        cin >> video[i];
    divide(video, 0, n-1, 0, n-1);
    return (0);
}