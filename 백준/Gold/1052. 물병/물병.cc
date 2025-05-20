#include <stdio.h>

int countone(int n)
{
    int count=0;
    while(n!=0)
    {
        if(n%2==1) count++;
        n/=2;
    }
    return count;
}

int main(void)
{
    int n, k;
    scanf("%d %d", &n, &k);

    int add=0;
    while(countone(n) > k)
    {
        n++;
        add++;
    }

    printf("%d\n", add);
    return 0;
}