#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 2500

char s[MAX + 1];
bool pal[MAX][MAX];
int dp[MAX];

int main(void)
{
    scanf("%s", s);
    int n = strlen(s);
    for(int i=0; i<n; i++) pal[i][i] = true;
    
    for(int length=2; length<=n; length++)
    {
        for(int i=0; i<=n-length; i++)
        {
            int j = i + length - 1;
            if(s[i] == s[j])
            {
                if (length == 2) pal[i][j] = true;
                else pal[i][j] = pal[i+1][j-1];
            }
            else pal[i][j] = false;
        }
    }

    for(int i=0; i<n; i++)
    {
        if(pal[0][i]) dp[i] = 1;
        else
        {
            dp[i] = 1 << 30;
            for(int j=1; j<=i; j++)
            {
                if(pal[j][i] && dp[j-1]+1 < dp[i]) dp[i] = dp[j-1] + 1;
            }
        }
    }

    printf("%d\n", dp[n-1]);
    return 0;
}