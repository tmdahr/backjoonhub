#include <stdio.h>

int main(void)
{
    int n;
    int num[1001];
    int dp[1001];

    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &num[i]);
        dp[i] = 1;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(num[j] > num[i] && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
        }
    }

    int max = 0;
    for(int i=0; i<n; i++)
    {
        if(dp[i] > max) max = dp[i];
    }

    printf("%d\n", max);
    return 0;
}