// 별 찍기 -4 bj.2441
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N;

    scanf("%d", &N);
    for (int i=0; i<N; i++)
    {
        for (int j=N; j>0; j--)
        {
            if (j <= N - i)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return (0);
}