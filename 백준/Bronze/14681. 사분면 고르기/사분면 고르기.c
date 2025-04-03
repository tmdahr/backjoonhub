#include <stdio.h>

int main(void)
{
	int x, y, z;
	
	scanf("%d %d", &x, &y);
	
	if (x > 0)
	{
		if(y > 0)
		{
			z = 1;
		}
		else
		{
			z = 4;
		}
	}
	else
	{
		if(y > 0)
		{
			z = 2;
		}
		else
		{
			z = 3;
		}
	}
	
	printf("%d", z);
	return 0;
}