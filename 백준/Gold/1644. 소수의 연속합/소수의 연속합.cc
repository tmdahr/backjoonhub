#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int n, len=0, count = 0;
    int prime[282600];
    bool is_prime[4000005];
    
    scanf("%d", &n);
    for(int i=2; i<=n; i++)
        is_prime[i] = true;

    for(int i=2; i*i <= n; i++)
        if(is_prime[i])
            for(int j = i * i; j <= n; j += i)
                is_prime[j] = false;
    for(int i=2; i<=n; i++)
        if(is_prime[i])
            prime[len++] = i;
    
    for(int i=0; i<len; i++)
    {
        int sum=0;
        for(int j=i; j<len; j++)
        {
            sum+=prime[j];
            if(sum>=n)
            {
                if(sum==n) count++;
                break;
            }
        }
    }
    printf("%d\n", count);

    return 0;
}