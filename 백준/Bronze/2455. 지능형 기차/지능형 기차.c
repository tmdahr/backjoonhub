#include <stdio.h>

int main(void)
{
	int n, m, i, l = 0, j = 0;
	
	for(i = 4; i > 0; i--)
	{
		scanf("%d %d", &n, &m);
		j = j - n + m;
		if (l < j)
		{
			l = j;
		}
	}
	printf("%d", l);
	
	return 0;
}