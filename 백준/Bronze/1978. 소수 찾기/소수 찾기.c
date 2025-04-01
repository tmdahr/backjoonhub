#include <stdio.h>

int main(void)
{
	int n, m, i, l = 0;
	scanf("%d", &n);
	
	while(n > 0)
	{
		scanf("%d", &m);
		for (i = 2; i <= m; i++)
		{
			if(m % i == 0 && m == i)
			{
				l++;
			}
			if(m % i == 0 && m > i)break;
		}
		n--;
	}
	printf("%d", l);
	
	return 0;
}