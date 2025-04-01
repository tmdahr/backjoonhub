#include <stdio.h>
int main(void)
{
	int c, nn, i, vud;
	double gkq = 0, ekq;
	int n[1000];
	
	scanf("%d", &c);
	for(; 0 < c; c--)
	{
		scanf("%d", &nn);
		vud=0;
		gkq=0;
		ekq=0;
		for(i = 0; i < nn; i++)
		{
			scanf("%d", &n[i]);
			gkq = gkq + (double)n[i];
		}
		gkq = gkq / (double)nn;
		for(i = 0; i < nn; i++)
		{
			if(gkq < (double)n[i])
			{
				vud++;
			}
		}
		ekq = (double)vud * 100.0 / (double)nn;
		printf("%.3lf%%\n", ekq);
	}
	
	return 0;
}