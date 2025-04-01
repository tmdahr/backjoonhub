#include <stdio.h>

int main(void)
{
	int i = 1, l, j, k, t;
	
	scanf("%d", &j);
	
	for (l = 0; l < j; j--)
	{
		while (k < j)
		{
			printf(" ");
			k++;
		}
		k = 1;
		while (t < i)
		{
			printf("*");
			t++;
		}
		i++;
		t = 0;
		printf("\n");
	}
	return 0;
}