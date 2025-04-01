#include <stdio.h>

int main(void)
{
	int i, l, j;
	
	scanf("%d", &j);
	j++;
	
	for(l = 1; l < j; l++)
	{
		for(i = 0; i < l; i++)
		{
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}