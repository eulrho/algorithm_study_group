// 별 찍기 -8 bj.2445
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N, mid;

    scanf("%d", &N);
    mid = N;
    N *= 2;
    for (int i=1; i<N; i++)
    {
        for (int j=1; j<=N; j++)
        {
            if (i <= mid)
            {
                if (j <= i || j > N-i)
                    printf("*");
                else
                    printf(" ");
            }
            else
            {
                if (j > i || j <= N-i)
                    printf("*");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }
    return (0);
}