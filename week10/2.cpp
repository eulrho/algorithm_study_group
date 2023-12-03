// 블랙잭 bj.2798
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, m, sum=0, temp;
    int arr[100];

    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> arr[i];
    for (int i=n-1; i>=2; i--) {
        if (arr[i] >= m) continue ;
        for (int j=i-1; j>=1; j--) {
            if (arr[i] + arr[j] >= m) continue ;
            for (int k=j-1; k>=0; k--) {
                if (arr[i] + arr[j] + arr[k] > m) continue ;
                else
                {
                    temp = arr[i] + arr[j] + arr[k];
                    if (temp > sum) sum = temp;
                }
            }
        }
    }
    cout << sum;
    return (0);
}