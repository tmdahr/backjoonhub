#include <stdio.h>

int main(void)
{
	int i, j, n, m, l, k;
	scanf("%d", &n);
	m = n - 1;
	l = 1;
	
	for (i = 0; i < n; i++)
	{
		j = 0;
		while(j < m)
		{
			printf(" ");
			j++;
		}
		m--;
		
		k = 0;
		while (k < l)
		{
			printf("*");
			k++;
		}
		l = l + 2;
		
		printf("\n");
	}
	return 0;
}