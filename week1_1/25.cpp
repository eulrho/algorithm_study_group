// 별 찍기 -12 bj.2522
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N, mid;

    scanf("%d", &N);
    mid = N;
    for (int i=1; i<2*N; i++)
    {
        for (int j=1; j<=N; j++)
        {
            if (i <= mid)
            {
                if (j > N-i)
                    printf("*");
                else
                    printf(" ");
            }
            else
            {
                if (j > i - mid)
                    printf("*");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }
    return (0);
}