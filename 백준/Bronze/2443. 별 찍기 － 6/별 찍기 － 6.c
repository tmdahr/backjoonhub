#include <stdio.h>

int main(void)
{
	int i, j, n, m, l, k;
	scanf("%d", &n);
	m = 0;
	
	for (i = 0; i < n; n--)
	{
		for (j = 0; j < m; j++)
		{
			printf(" ");
		}
		m++;
		
		l = n + (n - 1);
		for (k = 0; k < l; k++)
		{
			printf("*");
		}
		
		printf("\n");
	}
	return 0;
}