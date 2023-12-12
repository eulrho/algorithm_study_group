// 숫자 야구 bj.2503
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int num_arr[100];
int str_arr[100];
int ball_arr[100];

bool check(int i, int j)
{
    string num, sample;
    int str=0, ball=0;

    num = to_string(num_arr[j]);
    sample = to_string(i);
    for (int k=0; k<3; k++) {
        for (int m=0; m<3; m++) {
            if (sample[k] == num[m] && k == m) str++;
            if (sample[k] == num[m] && k != m) ball++;
        }
    }
    return (str_arr[j] == str && ball_arr[j] == ball);
}

bool is_valid_num(int num)
{
    string s = to_string(num);

    if (s[0] == '0' || s[1] == '0' || s[2] == '0') return (false);
    return (s[0] != s[1] && s[1] != s[2] && s[0] != s[2]);
}

int main()
{
    fast;
    int n, cnt=0;

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> num_arr[i] >> str_arr[i] >> ball_arr[i];
    }
    for (int i=123; i<=987; i++) {
        if (!is_valid_num(i)) continue ;
        for (int j=0; j<n; j++) {
            if (!check(i, j)) break ;
            if (j == n-1) cnt++;
        }
    }
    cout << cnt;
    return (0);
}