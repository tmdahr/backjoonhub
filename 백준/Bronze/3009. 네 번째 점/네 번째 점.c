#include <stdio.h>

int main(void)
{
	int x1, x2, x3, x4, y1, y2, y3, y4;
	scanf("%d %d", &x1, &y1);
	scanf("%d %d", &x2, &y2);
	scanf("%d %d", &x3, &y3);
	
	if(x1 == x2)
	{
		x4 = x3;
	}
	else if(x2 == x3)
	{
		x4 = x1;
	}
	else if(x1 == x3)
	{
		x4 = x2;
	}
	
	if(y1 == y2)
	{
		y4 = y3;
	}
	else if(y2 == y3)
	{
		y4 = y1;
	}
	else if(y1 == y3)
	{
		y4 = y2;
	}
	
	printf("%d %d", x4, y4);
	
	return 0;
}