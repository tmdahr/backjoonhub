#include <stdio.h>

int main(void) {
    long long N;
    scanf("%lld", &N);
    
    long long result = (N - 1) * N * (N + 1) / 2;
    
    printf("%lld\n", result);
    return 0;
}