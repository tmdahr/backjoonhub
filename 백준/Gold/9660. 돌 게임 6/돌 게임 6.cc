#include <stdio.h>

int main(void)
{
    long long n;
    scanf("%lld", &n);
    if(n % 7 == 0 || n % 7 == 2) printf("CY\n");
    else printf("SK\n");
    return 0;
}
