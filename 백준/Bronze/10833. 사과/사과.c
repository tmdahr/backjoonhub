#include <stdio.h>

int main(void)
{
	int n, m, i, l, j = 0;
	scanf("%d", &n);
	
	for (m = 1; m <= n; m++)
	{
		scanf("%d %d", &i, &l);
		j = j + l % i;
	}
	printf("%d", j);
	
	return 0;
}