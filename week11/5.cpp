// 행렬 bj.1080
#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, m, cnt=0;
    string num;
    string procession[50];

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> procession[i];
    }
    for (int i=0; i<n; i++) {
        cin >> num;
        for (int j=0; j<m; j++) {
            if (procession[i][j] != num[j])
                procession[i][j] = '0';
            else
                procession[i][j] = '1';
        }
    }
    for (int i=0; i<n-2; i++) {
        for (int j=0; j<m-2; j++) {
            if (procession[i][j] == '0') {
                cnt++;
                for (int k=0; k<3; k++) {
                    for (int l=0; l<3; l++) {
                        if (procession[i+k][j+l] == '0')
                            procession[i+k][j+l] = '1';
                        else
                            procession[i+k][j+l] = '0';
                    }
                }
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (procession[i][j] == '0') {
                cout << -1;
                return (0);
            }
        }
    }
    cout << cnt;
    return (0);
}
