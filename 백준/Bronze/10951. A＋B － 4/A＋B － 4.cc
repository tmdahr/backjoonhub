#include <stdio.h>
int main(void)
{
    int a, b;
    while(1)
    {
        if(scanf("%d %d", &a, &b)==EOF) break;
        printf("%d\n", a+b);
    }

    return 0;
}