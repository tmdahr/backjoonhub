#include <stdio.h>

long long gcd(long long a, long long b) {return b ? gcd(b, a % b) : a;}

int main(void)
{
    long long g, l;
    scanf("%lld %lld", &g, &l);
    long long d = l / g;

    long long min = 4e18;
    long long ans_a = 0, ans_b = 0;

    for(long long i=1; i*i<=d; i++)
    {
        if(d%i == 0)
        {
            long long j = d / i;
            if(gcd(i,j) == 1)
            {
                if(i+j < min)
                {
                    min = i+j;
                    ans_a = i*g;
                    ans_b = j*g;
                }
            }
        }
    }
    printf("%lld %lld\n", ans_a, ans_b);
    return 0;
}