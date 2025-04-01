#include <stdio.h>
int main(void)
{
	int n, nm, m;
	scanf("%d", &n);
	
	for(m = 0; n > 0; m++)
	{
		if(n == 5 || n >= 7)
		{
			if(n < 9 || n > 9)
			{
				if(n < 12 || n > 12)
				{
					nm = 5;
				}
				else if(n >= 3)
				{
					nm = 3;
				}
			}
			else if(n >= 3)
			{
				nm = 3;
			}
		}
		else if(n >= 3)
		{
			nm = 3;
		}
		else if (n > 2) break;
		
		n = n - nm;
	}
	
	if(n == 0)
	{
		printf("%d", m);
	}
	else
	{
		printf("-1");
	}
	
	return 0;
}