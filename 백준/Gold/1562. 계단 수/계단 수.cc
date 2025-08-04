#include <stdio.h>
#include <string.h>

#define MOD 1000000000

int N;
int dp[101][10][1024];

int main(void)
{
    scanf("%d", &N);
    for(int i=1; i<=9; i++) dp[1][i][1<<i] = 1;

    for(int length=1; length<N; length++)
    {
        for(int digit=0; digit<=9; digit++)
        {
            for(int mask=0; mask<1024; mask++)
            {
                if (dp[length][digit][mask] == 0) continue;
                int cur = dp[length][digit][mask];

                if(digit-1 >= 0)
                {
                    int new_mask = mask | (1 << (digit-1));
                    dp[length+1][digit-1][new_mask] = (dp[length+1][digit-1][new_mask] + cur) % MOD;
                }
                if(digit+1 <= 9)
                {
                    int new_mask = mask | (1 << (digit+1));
                    dp[length+1][digit+1][new_mask] = (dp[length+1][digit+1][new_mask] + cur) % MOD;
                }
            }
        }
    }

    int full_mask = (1 << 10) - 1;
    int answer = 0;
    for(int digit=0; digit<=9; digit++) answer = (answer + dp[N][digit][full_mask]) % MOD;
    printf("%d\n", answer);
    
    return 0;
}