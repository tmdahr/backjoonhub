#include<stdio.h>
 
long int tri[101] = {0,1,1,1,2,2};    // tri[5]까지 초기화
 
int main(void)
{
    int t, n;
    scanf("%d", &t);
    for(; t>0; t--)
    {
        scanf("%d", &n);
        for(int i=6; i <= n; i++) tri[i] = tri[i-5]+tri[i-1];
        printf("%ld\n", tri[n]);
    }
	return 0;
}