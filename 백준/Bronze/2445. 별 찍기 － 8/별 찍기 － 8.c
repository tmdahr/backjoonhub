#include <stdio.h>

int main(void)
{
	int i, j, n, m, l, k;
	scanf("%d", &n);
	m = 1;
	l = n * 2 - 2;
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("*");
		}
		for (k = 0; k < l; k++)
		{
			printf(" ");
		}
		l = l - 2;
		for (j = 0; j < m; j++)
		{
			printf("*");
		}
		m++;
		
		printf("\n");
	}

	m = m - 2;
	l = 2;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("*");
		}
		for (k = 0; k < l; k++)
		{
			printf(" ");
		}
		l = l + 2;
		for (j = 0; j < m; j++)
		{
			printf("*");
		}
		m--;
		
		printf("\n");
	}
	return 0;
}