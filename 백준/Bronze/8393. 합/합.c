#include <stdio.h>

int main(void)
{
	int n, m, i = 0;
	scanf("%d", &n);
	
	for (m = 1; m <= n; m++)
	{
		i = i + m;
	}
	printf("%d", i);
	
	return 0;
}