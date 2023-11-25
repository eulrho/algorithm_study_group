// 종이의 개수 bj.1780
#include <iostream>
using namespace std;

int paper[3000][3000];
int ch[3]={0,};

bool is_full(int y_left, int y_right, int x_left, int x_right)
{
    int target = paper[y_left][x_left];

    for (int i=y_left; i<=y_right; i++) {
        for (int j=x_left; j<=x_right; j++) {
            if (target != paper[i][j]) return (false);
        }
    }
    ch[target+1]++;
    return (true);
}

void divide(int y_left, int y_right, int x_left, int x_right)
{
    int size;

    if (is_full(y_left, y_right, x_left, x_right) == true)
        return ;
    size = y_right - y_left + 1;
    if (size == 3) {
        for (int i=y_left; i<=y_right; i++) {
            for (int j=x_left; j<=x_right; j++) ch[paper[i][j]+1]++;
        }
    }
    else {
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                divide(y_left+size*i/3, y_left+size*(i+1)/3-1, x_left+size*j/3, x_left+size*(j+1)/3-1);
            }
        }
    }
}

int main()
{
    int n;

    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) cin >> paper[i][j];
    }
    divide(0, n-1, 0, n-1);
    for (int i=0; i<3; i++)
        cout << ch[i] << '\n';
    return (0);
}