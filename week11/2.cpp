// 주식 bj.11501
#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int t, n;
    long long price, result, max;
    vector<long long> stock;

    cin >> t;
    for (int i=0; i<t; i++) {
        max = -1;
        result = 0;
        stock = vector<long long> ();
        cin >> n;
        for (int j=0; j<n; j++) {
            cin >> price;
            stock.push_back(price);
        }
        for (int j=n-1; j>=0; j--) {
            if (max > stock[j]) {
                result += max - stock[j];
            }
            else
                max = stock[j];
        }
        cout << result << '\n';
    }
    return (0);
}