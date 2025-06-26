#include <stdio.h>
 
int main(void)
{
    int dp[11] = {0,1,2,4};
 
    for(int i=4; i < 11; i++) dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
 
    int t, n;
    scanf("%d", &t);
 
    for(int tc = 0; tc < t; tc++)
    {
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
 
    return 0;
}