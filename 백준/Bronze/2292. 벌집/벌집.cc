#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    n--;
    int sum=1;
    if(n!=0)
    {
        for(int i=1; n>0; i++)
        {
            n-=6*i;
            sum++;
        }
    }
    printf("%d", sum);

    return 0;
}