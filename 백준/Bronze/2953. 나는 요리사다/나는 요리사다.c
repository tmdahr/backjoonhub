#include <stdio.h>
int main(void)
{
	int tn[20];
	int i, n = 0, m;
	
	for(i = 0; i < 20; i++)
	{
		scanf("%d", &tn[i]);
	}
	for(i = 0; i < 20; i++)
	{
		if(i % 4 == 0)
		{
			tn[i] = tn[i] + tn[i+1] + tn[i+2] + tn[i+3];
		}
	}
	for(i = 0; i < 20; i++)
	{
		if(n < tn[i])
		{
			n = tn[i];
			m = i / 4 + 1;
		}
	}
	
	printf("%d\n%d", m, n);
	
	return 0;
}