// 별 찍기 -1 bj.2438
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N;

    scanf("%d", &N);
    for (int i=1; i<=N; i++)
    {
        for (int j=0; j<i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return (0);
}