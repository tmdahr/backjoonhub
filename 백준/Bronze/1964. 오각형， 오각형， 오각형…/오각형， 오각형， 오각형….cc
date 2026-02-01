#include <stdio.h>

#define MOD 45678

int main(void) {
    long long N;
    scanf("%lld", &N);

    long long val = 3*N*N + 5*N + 2;
    long long ans = (val / 2) % MOD;

    printf("%lld\n", ans);
    return 0;
}
