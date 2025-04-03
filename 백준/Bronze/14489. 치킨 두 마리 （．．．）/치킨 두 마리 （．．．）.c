#include <stdio.h>

int main(void)
{
	int a, b, c, d;
	scanf("%d %d", &a, &b);
	scanf("%d", &c);
	
	a = a + b;
	c = c * 2;
	d = (a >= c) ? a - c : a;
	printf("%d", d);
	
	return 0;
}