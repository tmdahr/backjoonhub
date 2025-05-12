#include <stdio.h>
int main(void)
{
    int a, b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    printf("%d\n", a+b-c);
    if(b==1000) printf("%d\n", 10000*a+b-c);
    else if(b/100 > 0) printf("%d\n", 1000*a+b-c);
    else if(b/10 > 0) printf("%d\n", 100*a+b-c);
    else printf("%d\n", 10*a+b-c);
    return 0;
}