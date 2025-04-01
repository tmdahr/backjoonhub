#include <stdio.h>
int main(void)
{
	int m[1000];
	int n, p, i, j;
	scanf("%d %d",&n,&p);
	m[0] = n;
	for(i=1; i<1000; i++)
	{
		m[i]= m[i-1]*n%p;
	}
	for(j=0; j<1000; j++)
	{
		for(i=j+1; i<1000; i++) 
		{
			if(m[j] == m[i]) break;
		}
		if(m[j] == m[i]) break;
	}
	printf("%d", i-j);
	
	return 0;
}