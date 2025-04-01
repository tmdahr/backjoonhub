#include <stdio.h>
int main(void)
{
	char n[51][6][8];
	int m, i, l, j, c, v, mc=0, mv1, mv2;
	
	scanf("%d", &m);
	for(j=0; j<m; j++)
	{
		for(i=0; i<5; i++)
		{
			scanf("%s", &n[j][i]);
		}
	}
	if(m==2)
	{
		mv1=1;
		mv2=2;
	}
	else 
	{
		for(v=0; v<m; v++)
		{
			for(j=1; j<=m-v; j++)
			{
				c=0;
				for(i=0; i<5; i++)
				{
					for(l=0; l<7; l++)
					{
						if(n[v][i][l]==n[v+j][i][l]) c++;
					}
				}
				if(c>mc)
				{
					mv1=v;
					mv2=v+j;
					mc=c;
				}
			}
		}
		mv1++;
		mv2++;
	}
	printf("%d %d", mv1, mv2);
	
	return 0;
}