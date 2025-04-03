#include <stdio.h>

int main(void)
{
	int t, r, v, e, n;
	scanf("%d", &t);
	
	for (r = 1; r <= t; r++)
	{
		scanf("%d %d", &v, &e);
		n = e - v + 2;
		printf("%d\n", n);
	}
	
	return 0;
}