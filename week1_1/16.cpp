// 2007년 bj.1924
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int x, y, diff = 0;

    scanf("%d %d", &x, &y);
    diff += y;
    x--;
    while (x >= 1)
    {
        if (x == 1 || x == 3 || x == 5 || x == 7 || x == 8 || x == 10 || x == 12)
            diff += 31;
        else if (x == 4 || x == 6 || x == 9 || x == 11)
            diff += 30;
        else
            diff += 28;
        x--;
    }
    diff--;
    switch (diff % 7) {
        case 0 :
            printf("MON");
            break;
        case 1 :
            printf("TUE");
            break;
        case 2 :
            printf("WED");
            break;
        case 3 :
            printf("THU");
            break;
        case 4 :
            printf("FRI");
            break;
        case 5 :
            printf("SAT");
            break;
        case 6 :
            printf("SUN");
            break;
    }
    return (0);
}