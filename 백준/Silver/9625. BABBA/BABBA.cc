#include <stdio.h>

int main(void)
{
    int K;
    scanf("%d", &K);
    long long a = 0, b = 1;

    for(int i = 1; i < K; i++)
    {
        long long nextA = b;         
        long long nextB = a + b;    
        a = nextA;
        b = nextB;
    }

    printf("%lld %lld\n", a, b);
    return 0;
}