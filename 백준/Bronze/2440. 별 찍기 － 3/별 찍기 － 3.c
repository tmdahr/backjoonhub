#include <stdio.h>

int main(void)
{
	int i, j, n;
	scanf("%d", &n);
	
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
	}
	return 0;
}