#include <stdio.h>
int main(void)
{
	int i, l = 0, n = 0;
	int ghf[7];
	for(i=0; i<7; i++)
	{
		scanf("%d", &ghf[i]);
		if(ghf[i]%2 == 1)
		{
			n = n + ghf[i];
			if(l == 0 || l > ghf[i])
			{
				l = ghf[i];
			}
		}
	}
	if(n == 0)
	{
		printf("-1");
	}
	else
	{
		printf("%d\n%d", n, l);
	}
	
	return 0;
}