#include <cstdio>

int main(void)
{
    int n, count=0;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        int sum=0;
        for(int j=i; j<=n; j++)
        {
            sum+=j;
            if(sum==n)
            {
                count+=1;
                break;
            }
            if(sum>n) break;
        }
    }
    printf("%d\n", count);
    
    return 0;
}