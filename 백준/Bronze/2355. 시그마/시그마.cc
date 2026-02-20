#include <stdio.h>

int main(void)
{
    long long A, B;
    scanf("%lld %lld", &A, &B);

    long long first = A < B ? A : B;
    long long last  = A > B ? A : B;

    long long n = last - first + 1;
    long long sum = (first + last) * n / 2;

    printf("%lld\n", sum);
    return 0;
}
