// 달팽이는 올라가고 싶다 bj.2869
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cmath>

int main() {
    int a, b, v, day;

    scanf("%d %d %d", &a, &b, &v);
    day = (int)ceil((double)(v - a) / (a - b)) + 1;
    printf("%d", day);
    return (0);
}