// 정수 삼각형 bj.1932
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int max_path(int n, int arr[][501])
{
    int temp;

    for (int i=n-1; i>=1; i--) {
        for (int j=1; j<=i; j++) {
            temp = arr[i+1][j] > arr[i+1][j+1] ? arr[i+1][j] : arr[i+1][j+1];
            arr[i][j] += temp;
        }
    }
    return (arr[1][1]);
}

int main()
{
    fast;
    int n, triangle[501][501];

    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            cin >> triangle[i][j];
        }
    }
    cout << max_path(n, triangle);
    return (0);
}