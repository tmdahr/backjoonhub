#include <stdio.h>

int main(void)
{
	int i, j, n, m, l;
	scanf("%d", &n);
	m = 1;
	
	for (i = 0; i < n;)
	{
		for (j = 0; j < n; n--)
		{
			while(j < n)
			{
				printf("*");
				j++;
			}
		}
		printf("\n");
		
		l = 0;
		while(l < m)
		{
			printf(" ");
			l++;
		}
		m++;
	}
	
	return 0;
}