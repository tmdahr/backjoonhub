#include <stdio.h>

int main(void)
{
	int i, l, n, m, j, k;
	scanf("%d", &n);
	m = n - 1;
	j = 1;
	
	for (i = 0; i < n; i++)
	{
		for (l = 0; l < m; l++)
		{
			printf(" ");
		}
		m--;
		
		for (k = 0; k < j; k++)
		{
			printf("*");
		}
		j = j + 2;
		
		printf("\n");
	}
	
	n--;
	m = 1;
	j = j - 4;
	for (i = 0; i < n; i++)
	{
		for (l = 0; l < m; l++)
		{
			printf(" ");
		}
		m++;
		
		for (k = 0; k < j; k++)
		{
			printf("*");
		}
		j = j - 2;
		
		printf("\n");
	}
	return 0;
}