#include <stdio.h>
int main(void)
{
	int num[1005][1005]={0, };
	int n, m, i, l, j, x, y, a, b;
	
	scanf("%d", &n);
	for(j=1; j<=n; j++)
	{
		scanf("%d %d %d %d", &x, &y, &i, &l);
		for(a=x; a<x+i; a++)
		{
			for(b=y; b<y+l; b++)
			{
				num[a][b]=j;
			}
		}
	}
	for(j=1; j<=n; j++)
	{
		m=0;
		for(i=0; i<1005; i++)
		{
			for(l=0; l<1005; l++)
			{
				if(num[i][l]==j) m++;
			}
		}
		printf("%d\n", m);
	}

	return 0;
}