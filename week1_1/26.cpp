// 별 찍기 -9 bj.2446
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
                if (j < i)
                    printf(" ");
                else if (j <= N - i)
                    printf("*");
            }
            else
            {
                if (j < N-i)
                    printf(" ");
                else if (j <= i)
                    printf("*");
            }
        }
        printf("\n");
    }
    return (0);
}