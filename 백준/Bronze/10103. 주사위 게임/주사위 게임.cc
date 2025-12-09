#include <stdio.h>

int main(void)
{
    int x = 100;
    int y = 100;
    int n,i;
    int a,b;

    scanf("%d",&n);
    for(i = 0; i<n; i++)
    {
        scanf("%d %d",&a,&b);
        
        if(a < b) x = x - b;
        else if(a > b) y = y - a;
        else if(a == b) continue;
    }
    printf("%d\n",x);
    printf("%d\n",y);
}