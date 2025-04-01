#include <stdio.h>
int main(void)
{
	char tn[9];
	int i, n = 0, m;
	
	for(i = 0; i < 9; i++)
	{
		scanf("%d", &tn[i]);
	}
	for(i = 0; i < 10; i++)
	{
		if(n < tn[i])
		{
			n = tn[i];
			m = i + 1;
		}
	}
	
	printf("%d\n%d", n, m);
	
	return 0;
}