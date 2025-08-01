#include <stdio.h>

long long dp[91];

int main(void)
{
    int n;
    scanf("%d", &n);

    dp[1] = 1;
    dp[2] = 1;

    for(int i=3; i<=n; i++) dp[i] = dp[i-1] + dp[i-2];

    printf("%lld\n", dp[n]);
    return 0;
}