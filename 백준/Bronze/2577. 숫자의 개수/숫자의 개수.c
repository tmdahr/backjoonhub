#include <stdio.h>
int main(void)
{
	int n[10]={0};
	int a, b, c, m, i, mi;
	scanf("%d %d %d",&a,&b,&c);
	for(m=a*b*c; ; m=m/10)
	{
		mi = m%10;
		n[mi]++;
		if(m/10==0) break;
	}
	for(i=0; i<10; i++) printf("%d\n", n[i]);
	
	return 0;
}