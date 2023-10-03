// 최대공약수와 최소공배수 bj.2609
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int find_common_divisor(int num1, int num2) {
    int max = 1, i = 2;
    int low = (num1 > num2)? num1 : num2;

    while (low >= i)
    {
        if (num1 % i == 0 && num2 % i == 0)
        {
            if (max < i)
                max = i;
        }
        i++;
    }
    return (max);
}

int main() {
    int num1, num2, g, l;

    scanf("%d %d", &num1, &num2);
    g = find_common_divisor(num1, num2);
    l = (num1 / g) * (num2 / g) * g;
    printf("%d\n%d", g, l);
    return (0);
}