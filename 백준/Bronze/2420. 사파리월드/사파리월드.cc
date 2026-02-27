#include <stdio.h>

int main(void) {
    long long N, M;
    scanf("%lld %lld", &N, &M);

    long long diff = N - M;
    if(diff < 0) diff = -diff;

    printf("%lld\n", diff);
    return 0;
}