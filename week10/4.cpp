// 한윤정이 이탈리아에 가서 아이스크림을 사먹는데 bj.2422
#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, m, ice_cream, no_mix, cnt=0;
    vector<int> arr[201];

    cin >> n >> m;
    for (int i=0; i<m; i++) {
        cin >> ice_cream >> no_mix;
        arr[ice_cream].push_back(no_mix);
        arr[no_mix].push_back(ice_cream);
    }
    if (n >= 3) {
        for (int i=n; i>=3; i--) {
            for (int j=i-1; j>=2; j--) {
                // 3, 2
                if (find(arr[i].begin(), arr[i].end(), j) != arr[i].end())
                    continue ;
                for (int k=j-1; k>=1; k--) {
                    // 3, 1
                    if (find(arr[i].begin(), arr[i].end(), k) != arr[i].end())
                        continue ;
                    // 2, 1
                    if (find(arr[j].begin(), arr[j].end(), k) != arr[j].end())
                        continue ;
                    cnt++;
                }
            }
        }
    }
    cout << cnt;
    return (0);
}