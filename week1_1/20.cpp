// 별 찍기 -2 bj.2439
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N;

    scanf("%d", &N);
    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=N; j++)
        {
            if (j <= N - i)
                printf(" ");
            else
                printf("*");
        }
        printf("\n");
    }
    return (0);
}