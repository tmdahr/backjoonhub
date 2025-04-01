#include <stdio.h>

int main(void)
{
	int n, m, i;
	scanf("%d", &n);
	
	for (i = 1; i < 10; i++)
	{
		scanf("%d", &m);
		n = n - m;
	}
	printf("%d", n);
	
	return 0;
}