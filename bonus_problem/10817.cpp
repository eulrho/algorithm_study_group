// 세 수 bj.10817
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main()
{
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);
    if ((a >= b && c >= a )|| (a >= c && b >= a)) printf("%d", a);
    else if ((b >= a && c >= b)||(b >= c && a >= b)) printf("%d", b);
    else if ((c >= b && a >= c)||(c >= a && b >= c)) printf("%d", c);
    return (0);
}