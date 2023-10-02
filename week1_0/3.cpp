// 세탁소 사장 동혁
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void solution(int C, int *q, int *d, int *n, int *p) {
    if (C / 25 > 0)
    {
        *q = C / 25;
        C %= 25;
    }
    if (C / 10 > 0)
    {
        *d = C / 10;
        C %= 10;
    }
    if (C / 5 > 0)
    {
        *n = C / 5;
        C %= 5;
    }
    if (C != 0)
        *p = C;
}

int main() {
    int T, C;

    scanf("%d", &T);
    for (int i=0; i<T; i++)
    {
        int q = 0, d = 0, n = 0, p = 0;

        scanf("%d", &C);
        solution(C, &q, &d, &n, &p);
        printf("%d %d %d %d", q, d, n, p);
        if (i != T-1)
            printf("\n");
    }
    return (0);
}