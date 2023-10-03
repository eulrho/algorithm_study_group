// 소수 찾기 bj.1978
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void is_prime(int num, int *cnt) {
    int i=2;
    if (num <= 1)
        return ;
    while (i <= num / i)
    {
        if (num % i == 0)
            return ;
        i++;
    }
    (*cnt)++;
}

int main() {
    int N, num, cnt = 0;

    scanf("%d", &N);
    for (int i=0; i < N; i++) {
        scanf("%d", &num);
        is_prime(num, &cnt);
    }
    printf("%d", cnt);
    return (0);
}