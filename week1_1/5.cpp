// A+B -4 bj.10951
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int A, B;

    while (scanf("%d", &A) != EOF)
    {
        scanf("%d", &B);
        printf("%d\n", A+B);
    }
    return (0);
}