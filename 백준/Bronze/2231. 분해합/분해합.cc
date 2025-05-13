#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        int sum=i, num=i;
        while(num!=0)
        {
            sum+=num%10;
            num/=10;
        }
        if(sum==n)
        {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("0\n");
    return 0;

    return 0;
}