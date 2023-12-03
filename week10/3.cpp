// 슈퍼 마리오 bj.2851
#include <iostream>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int scores[10], sum=0, temp;

    for (int i=0; i<10; i++) cin >> scores[i];
    for (int i=0; i<10; i++) {
        temp = scores[i];
        if (temp + sum < 100 || sum == 0) sum += temp;
        else {
            if (temp + sum == 100) sum += temp;
            else {
                if (abs(sum+temp-100) <= abs(sum-100)) sum += temp;
            }
            break ;
        }
    }
    cout << sum;
    return (0);
}