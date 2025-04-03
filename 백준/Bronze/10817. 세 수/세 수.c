#include <stdio.h>

int main(void)
{
	int a, b, c, ekq;
	scanf("%d %d %d", &a, &b, &c);
	
	ekq = (a >= b) ? a : b;
	ekq = (ekq >= c) ? ekq : c;
	
	if(ekq == a)
	{
		ekq = (b > c) ? b : c;
	}
	else if(ekq == b)
	{
		ekq = (a > c) ? a : c;
	}
	else
	{
		ekq = (a > b) ? a : b;
	}
	printf("%d", ekq);
		
	return 0;
}