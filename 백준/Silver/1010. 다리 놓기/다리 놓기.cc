#include <stdio.h>

int main(void)
{
    int t, n, m;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%d %d", &n, &m);
        long long result = 1;
        for(int i=1; i <= n; i++)
        {
            result *= (m-i+1);
            result /= i;
        }
        printf("%lld\n", result);
    }

    return 0;
}