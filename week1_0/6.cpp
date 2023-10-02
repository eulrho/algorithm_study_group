// 분수찾기 bj.1193
#include <iostream>

using namespace std;

int find_target(int X, int *cnt) {
    int pre=1, target=1, i=1, num=1;

    *cnt = 1;
    while (1)
    {
        if (target >= X) {
            if (X - pre < target - X)
            {
                target = pre;
                (*cnt)--;
            }
            break;
        }
        pre = target;
        target += num;
        (*cnt)++;
        if (num == 1)
        {
            num = 4 * i;
            i++;
        }
        else
            num = 1;
    }
    return (target);
}

int main() {
    int X, target, cnt, num, deno;

    cin >> X;
    target = find_target(X, &cnt);
    num = 1, deno = cnt;
    if (target < X)
    {
        num += (X - target);
        deno -= (X - target);
    }
    else if (target > X)
    {
        num -= (X - target);
        deno += (X - target);
    }
    cout << num << '/' << deno;
    return (0);
}