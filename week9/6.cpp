// 사분면 bj.1891
#include <iostream>
#include <cmath>
#include <string>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

long long target_y=0;
long long target_x=0;

bool check_existence(long long size)
{
    return (target_x >= 0 && target_x < size && target_y >= 0 && target_y < size);
}

void find_pos(string num, int num_size)
{
    for (int i=0; i<num_size; i++) {
        switch (num[i]) {
            case '1' :
                target_x += pow(2, num_size) / pow(2, i+1);
                break ;
            case '2' :
                break ;
            case '3' :
                target_y += pow(2, num_size) / pow(2, i+1);
                break ;
            case '4' :
                target_y += pow(2, num_size) / pow(2, i+1);
                target_x += pow(2, num_size) / pow(2, i+1);
                break ;
        }
    }
}

string find_quadrant(int num_size)
{
    string num="";

    for (int i=0; i<num_size; i++) {
        if (pow(2, num_size) / pow(2, i+1) <= target_y && pow(2, num_size) / pow(2, i+1) <= target_x) {
            num += '4';
            target_y -= pow(2, num_size) / pow(2, i+1);
            target_x -= pow(2, num_size) / pow(2, i+1);
        }
        else if (pow(2, num_size) / pow(2, i+1) <= target_y && pow(2, num_size) / pow(2, i+1) > target_x) {
            num += '3';
            target_y -= pow(2, num_size) / pow(2, i+1);
        }
        else if (pow(2, num_size) / pow(2, i+1) > target_y && pow(2, num_size) / pow(2, i+1) <= target_x) {
            num += '1';
            target_x -= pow(2, num_size) / pow(2, i+1);
        }
        else num += '2';
    }
    return (num);
}

int main()
{
    fast;
    int num_size;
    long long x, y;
    string num;

    cin >> num_size >> num >> x >> y;
    find_pos(num, num_size);
    target_y -= y;
    target_x += x;
    if (!check_existence(pow(2, num_size))) cout << -1;
    else cout << find_quadrant(num_size);
    return (0);
}