#include <stdio.h>

int main(void)	
{
	int n, m = 0, i, j, l;
	
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &n);
		j = 100 - m;
		l = 100 - (m + n);
		if(j < 0)
		{
			j = j * -1;
		}
		if(l < 0)
		{
			l = l * -1;
		}
		m = m + n;
		
		if(m > 100)break;
	}
	if(j == l)
	{
		printf("%d", m);
	}
	else if (j > l)
	{
		printf("%d", m);
	}
	else
	{
		printf("%d", m - n);
	}
	
	return 0;
}