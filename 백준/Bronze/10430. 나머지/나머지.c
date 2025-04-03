#include <stdio.h>

int main(void)
{
	int A, B, C;
	int a, b, c, d;
	scanf("%d %d %d", &A, &B, &C);
	a = (A + B) % C;
	printf("%d\n", a);
	b = ((A % C) + (B % C)) % C;
	printf("%d\n", b);
	c = (A * B) % C;
	printf("%d\n", c);
	d = ((A % C) * (B % C)) % C;
	printf("%d\n", d);
	
	return 0;
}