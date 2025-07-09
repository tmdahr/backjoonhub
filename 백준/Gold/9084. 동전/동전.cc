#include <cstdio>

struct node
{
    int sum, num;
};

int main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m, count=0;
        int coin[25];
        int dp[10001]={0};
        
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d", &coin[i]);
        scanf("%d", &m);

        dp[0]=1;
        for(int i=0; i<n; i++)
        {
            for(int j=coin[i]; j<=m; j++)
            {
                dp[j] += dp[j-coin[i]];
            }
        }
        printf("%d\n", dp[m]);
    }
    
    return 0;
}