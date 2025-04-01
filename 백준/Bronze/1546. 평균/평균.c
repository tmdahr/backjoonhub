#include <stdio.h>
int main(void)
{
	int i, l;
	int tn[1000];
	double n = 0, m = 0;
	double ekq[1000];
	
	scanf ("%d", &l);
	for(i = 0; i < l; i++)
	{
		scanf("%d", &tn[i]);
	}
	for(i = 0; i < l; i++)
	{
		if(n < tn[i])
		{
			n = (double)tn[i];
		}
	}
	for(i = 0; i < l; i++)
	{
		ekq[i] = tn[i] / n * 100.0;
		m = m + ekq[i];
	}
	m = m / (double)l;
	
	printf("%.5lf", m);
	
	return 0;
} 