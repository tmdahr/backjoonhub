#include <stdio.h>

int main(void)
{
	int n, m, i, l;
	scanf("%d", &n);
	
	scanf("%d", &m);
	i = m;
	l = m;
	n--;
	while(n > 0)
	{
		scanf("%d", &m);
		n--;
		if (i >= m)
		{
			i = m;
		}
		if (l <= m)
		{
			l = m;
		}
	}
	printf("%d %d", i, l);
	
	return 0;
}