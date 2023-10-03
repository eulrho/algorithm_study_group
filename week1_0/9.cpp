// 소인수분해 bj.11653
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int is_prime(int N, int i) {
    while (i <= N / i)
    {
        if (N % i == 0)
            return (i);
        i++;
    }
    return (-1);
}

int main() {
    int N, i=2, prime;

    scanf("%d", &N);
    while (N > 1)
    {
        if (N % i != 0)
        {
            i++;
            prime = is_prime(N, i);
            if (prime == -1)
                i = N;
            continue;
        }
        else
        {
            printf("%d\n", i);
            N /= i;
        }
    }
    return (0);
}