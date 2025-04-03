#include <stdio.h>

int main(void)
{
	int t, r, a, b, c;
	scanf ("%d", &t);

	for (r = 1; r <= t; r++)
	{
		scanf("%d %d", &a, &b);
		c = a + b;
		printf("%d\n", c);
	}
	
	return 0;
}