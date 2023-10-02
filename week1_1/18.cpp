// 최소, 최대 bj.10818
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N, min = 1000000, max = -1000000, num;

    scanf("%d", &N);
    for (int i=0; i<N; i++)
    {
        scanf("%d", &num);
        if (num < min)
            min = num;
        if (num > max)
            max = num;
    }
    printf("%d %d", min, max);
    return (0);
}