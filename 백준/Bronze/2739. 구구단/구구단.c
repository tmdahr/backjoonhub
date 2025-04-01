#include <stdio.h>

int main(void)
{
	int n, m, e;
	scanf("%d", &n);
	
	for (m = 1; m < 10; m++)
	{
		e = n * m;
		printf("%d * %d = %d\n", n, m, e);
	}
	
	return 0;
}