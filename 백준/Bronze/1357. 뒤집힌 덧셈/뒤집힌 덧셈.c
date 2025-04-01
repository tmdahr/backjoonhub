#include <stdio.h>

int main(void)
{
	int x, y, xx = 0, yy = 0, xy, n, m = 1, z = 0;
	scanf("%d %d", &x, &y);
	
	if(x == 1000)
	{
		n = x;
		xx = xx + x / n;
	}
	else if(x < 10)
	{
		xx = x;
	}
	else if(x >= 100)
	{
		n = 100;
		while(x > 0)
		{
			xx = xx + x / n * m;
			x = x % n;
			n = n / 10;
			m = m * 10;
		}
	}
	else if(x >= 10)
	{
		n = 10;
		while(x > 0)
		{
			xx = xx + x / n * m;
			x = x % n;
			n = n / 10;
			m = m * 10;
		}
	}
	m = 1;
	if(y == 1000)
	{
		n = y;
		yy = yy + y / n;
	}
	else if(y < 10)
	{
		yy = y;
	}
	else if(y >= 100)
	{
		n = 100;
		while(y > 0)
		{
			yy = yy + y / n * m;
			y = y % n;
			n = n / 10;
			m = m * 10;
		}
	}
	else if(y >= 10)
	{
		n = 10;
		while(y > 0)
		{
			yy = yy + y / n * m;
			y = y % n;
			n = n / 10;
			m = m * 10;
		}
	}
	xy = xx + yy;
	m = 1;
	if(xy < 10)
	{
		z = xy;
	}
	else if(xy >= 1000)
	{
		n = 1000;
		while(xy > 0)
		{
			z = z + xy / n * m;
			xy = xy % n;
			n = n / 10;
			m = m * 10;
		}
	}
	else if(xy > 100)
	{
		n = 100;
		while(xy > 0)
		{
			z = z + xy / n * m;
			xy = xy % n;
			n = n / 10;
			m = m * 10;
		}
	}
	else if(xy >= 10)
	{
		n = 10;
		while(xy > 0)
		{
			z = z + xy / n * m;
			xy = xy % n;
			n = n / 10;
			m = m * 10;
		}
	}
	printf("%d", z);
	
	return 0;
}