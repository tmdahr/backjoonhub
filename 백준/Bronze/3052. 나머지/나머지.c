#include <stdio.h>
int main(void)
{
	int n[10];
	int m, i, l, j=0;
	for(i=0; i<10; i++)
	{
		scanf("%d", &m);
		n[i] = m % 42;
	}
	for(i=0; i<10; i++)
	{
		m = n[i];
		for(l=i+1; l<10; l++)
		{
			if(m == n[l]) n[l] = -1;
		}
	}
	for(i=0; i<10; i++)
	{
		if(n[i] != -1) j++;
	}
	printf("%d", j);
	
	return 0;
}