#include <stdio.h>

int main(void)
{
	int n, m, n1 = 31, n2 = 28, n3 = 31, n4 = 30, n5 = 31, n6 = 30, n7 = 31, n8 = 31, n9 = 30, n10 = 31, n11 = 30, i;
	scanf("%d %d", &n, &m);
	
	while(n > 1)
	{
		if(n == 2)
		{
			m = m + n1;
		}
		if(n == 3)
		{
			m = m + n2;
		}
		if(n == 4)
		{
			m = m + n3;
		}
		if(n == 5)
		{
			m = m + n4;
		}
		if(n == 6)
		{
			m = m + n5;
		}
		if(n == 7)
		{
			m = m + n6;
		}
		if(n == 8)
		{
			m = m + n7;
		}
		if(n == 9)
		{
			m = m + n8;
		}
		if(n == 10)
		{
			m = m + n9;
		}
		if(n == 11)
		{
			m = m + n10;
		}
		if(n == 12)
		{
			m = m + n11;
		}
		n--;
	}
	i = m % 7;
	
	if(i == 1)
	{
		printf("MON");
	}
	if(i == 2)
	{
		printf("TUE");
	}
	if(i == 3)
	{
		printf("WED");
	}
	if(i == 4)
	{
		printf("THU");
	}
	if(i == 5)
	{
		printf("FRI");
	}
	if(i == 6)
	{
		printf("SAT");
	}
	if(i == 0)
	{
		printf("SUN");
	}
	
	return 0;
}