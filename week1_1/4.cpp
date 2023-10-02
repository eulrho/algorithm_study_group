// A+B -3 bj.10950
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int T, A, B;

    scanf("%d", &T);
    for (int i=0; i<T; i++)
    {
        scanf("%d %d", &A, &B);
        printf("%d", A+B);
        if (i != T-1)
            printf("\n");
    }
    return (0);
}