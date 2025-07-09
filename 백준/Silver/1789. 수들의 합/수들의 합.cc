#include <cstdio>

int main(void)
{
    unsigned long long s, count=0;
    scanf("%llu", &s);
    for(int i=1; i<=s; i++)
    {
        s-=i;
        count++;
        if(s<=0) break; 
    }
    printf("%llu\n", count);
    
    return 0;
}