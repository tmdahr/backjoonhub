#include <stdio.h>

typedef struct _node
{
	char b;
	int t;
} node;
int r,c,n;
node map[205][205];
int dh[]={1,-1,0,0}, dw[]={0,0,1,-1};

int main(void)
{
	scanf("%d %d %d", &r, &c, &n);
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
		{
			char bomb;
			scanf(" %c", &bomb);
			if(bomb=='O') map[i][j]={bomb,2};
			else map[i][j]={bomb,0};
		}
	for(int l=1; l<n; l++)
	{
		if(l%2==1)
		{
			for(int i=0; i<r; i++)
				for(int j=0; j<c; j++)
				{
					if(map[i][j].b=='O') map[i][j].t--;
					else map[i][j]={'O',3};
				}
		}
		else
		{
			for(int i=0; i<r; i++)
				for(int j=0; j<c; j++)
				{
					if(map[i][j].b=='O')
					{
						map[i][j].t--;
						if(map[i][j].t==0)
						{
							map[i][j].b='.';
							for(int k=0; k<4; k++)
							{
								int hh=i+dh[k];
								int ww=j+dw[k];
								if(0<=hh&&hh<r&&0<=ww&&ww<c&&map[hh][ww].t!=1)
									map[hh][ww].b='.';
							}
						}
					}
				}
		}
	}
	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
			printf("%c", map[i][j].b);
		printf("\n");
	}
		
	return 0;
}