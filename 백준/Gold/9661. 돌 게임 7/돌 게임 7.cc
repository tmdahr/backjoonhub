#include <stdio.h>

int main(void)
{
    long long N;
    if(scanf("%lld", &N) != 1) return 0;
    int r = N % 5;
    if(r == 0 || r == 2) printf("CY\n");
    else printf("SK\n");
    return 0;
}