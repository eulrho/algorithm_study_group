// 별 찍기 -5 bj.2442
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N, mid;

    scanf("%d", &N);
    mid = N;
    for (int i=0; i<N; i++)
    {
        for (int j=1; j<2*N; j++)
        {
            if (j >= mid - i && j <= mid + i)
                printf("*");
            else if (j < mid - i)
                printf(" ");
        }
        printf("\n");
    }
    return (0);
}