#include <stdio.h>
#include <stdbool.h>

#define MAX 100001

int factor_count[MAX];
bool prime[MAX];

int main(void)
{
    int A, B;
    scanf("%d %d", &A, &B);

    for(int i=2; i<MAX; i++) prime[i] = true;
    for(int i=2; i*i<MAX; i++)
    {
        if(prime[i])
        {
            for(int j=i*i; j<MAX; j+=i) prime[j] = false;
        }
    }

    
    for(int i=2; i<MAX; i++)
    {
        if(factor_count[i] == 0)
        {
            for(int j=i; j<MAX; j+=i)
            {
                int num = j;
                while(num % i == 0)
                {
                    factor_count[j]++;
                    num /= i;
                }
            }
        }
    }

    int count = 0;
    for(int i=A; i<=B; i++)
        if(prime[factor_count[i]]) count++;

    printf("%d\n", count);
    return 0;
}