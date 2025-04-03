#include <stdio.h>
int main(void)
{
	int i, l, n, m = 0;
	scanf("%d %d", &i, &n);
	int tn[i], ekq[i];
	
	for(l = 0; l < i; l++)
	{
		scanf("%d", &tn[l]);
	}
	for(l = 0; l < i; l++)
	{
		if(n > tn[l])
		{
			ekq[m] = tn[l];
			m++;
		}
	}
	
	for(l = 0; l < m; l++)
	{
		printf("%d ", ekq[l]);
	}
	
	return 0; 
}