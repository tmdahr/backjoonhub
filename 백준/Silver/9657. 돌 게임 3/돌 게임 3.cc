#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d", &N);

    int dp[1001] = {0};
    dp[1] = 1;
    dp[2] = 0;
    dp[3] = 1;
    dp[4] = 1;

    for(int i=5; i<=N; i++)
    {
        if(dp[i-1] == 0 || dp[i-3] == 0 || dp[i-4] == 0) dp[i] = 1;
        else dp[i] = 0;
    }

    if(dp[N] == 1) printf("SK\n");
    else printf("CY\n");

    return 0;
}