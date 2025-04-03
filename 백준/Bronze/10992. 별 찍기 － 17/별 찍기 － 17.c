#include <stdio.h>

int main(void)
{
	int n, m, i = 1, l, j, k;
	scanf("%d", &n);
	j = n - 1;

	for (m = 0; m < n; m++)
	{
		for (k = 0; k < j; k++)
		{
			printf(" ");
		}
		j--;
		for (l = 0; l < i; l++)
		{
			if(m == n - 1)
			{
				printf("*");
			}
			else
			{
				if(l == 0 || l == i - 1)
				{
				    printf("*");
				}
				else
				{
				    printf(" ");
				}
			}
		}
		i = i + 2;
		printf("\n");
	}

	return 0;
}