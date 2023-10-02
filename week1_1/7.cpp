// A+B -6 bj.10953
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int T, A, B;
    char c;

    scanf("%d", &T);
    for (int i=0; i<T; i++)
    {
        scanf("%d%c%d", &A, &c, &B);
        printf("%d\n", A+B);
    }
    return (0);
}