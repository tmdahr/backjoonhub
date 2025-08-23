#include <stdio.h>

int main(void)
{
    int S, K;
    scanf("%d %d", &S, &K);

    int q = S / K;
    int r = S % K;
    long long ans = 1;
    
    for(int i = 0; i < r; i++) ans *= (q + 1);
    for(int i = 0; i < K - r; i++) ans *= q;

    printf("%lld\n", ans);
    return 0;
}
