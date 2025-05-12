#include <stdio.h>
int main(void)
{
    int n;
    int dp[1000001]={0,}, track[1000001];
    scanf("%d", &n);
    track[1] = 1;
    for(int i=2; i<=n; i++)
    {
        dp[i] = dp[i-1]+1;
        track[i] = i-1;
        if(i%2==0 && dp[i/2]+1 < dp[i])
        {
            dp[i] = dp[i/2]+1;
            track[i] = i/2;
        }
        if(i%3==0 && dp[i/3]+1 < dp[i])
        {
            dp[i] = dp[i/3]+1;
            track[i] = i/3;
        }
    }
    printf("%d\n", dp[n]);
    printf("%d ", n);
    while(n!=1)
    {
        printf("%d ", track[n]);
        n = track[n];
    }

    return 0;
}