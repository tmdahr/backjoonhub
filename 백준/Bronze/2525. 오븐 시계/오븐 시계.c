#include <stdio.h>

int main(void)
{
	int A, B, c;
	scanf("%d %d", &A, &B);
	scanf("%d", &c);
	B = B + c;
	A = A + B / 60;
	B = B % 60;
	
	if (A >= 24)
	{
		A = A - 24;
	}
	printf("%d %d", A, B);
	
	return 0;
}