#include <stdio.h>

int main(void)
{
	int i, j, l, n, m, k;
	scanf ("%d", &n);
	m = 0;
	k = n + (n - 1);
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf(" ");
		}
		m++;
		
		for (l = 0; l < k; l++)
		{
			printf("*");
		}
		k = k - 2;
		
		printf("\n");
	}
	
	n--;
	m = m - 2;
	k = 3;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf(" ");
		}
		m--;
		
		for (l = 0; l < k; l++)
		{
			printf("*");
		}
		k = k + 2;
		
		printf("\n");
	}
	return 0;
}