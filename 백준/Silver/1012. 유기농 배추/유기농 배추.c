#include <stdio.h>

int map[55][55]={0,};
int n,m;
int d[4]={1,-1,0,0};

void DFS(int h, int w)
{
	int hh, ww;
	map[h][w]=0;
	for(int i=0; i<4; i++)
	{
		hh=h+d[i];
		ww=w+d[3-i];
		
		if(0<=hh&&hh<m && 0<=ww&&ww<n)
		{
			if(map[hh][ww]==1) DFS(hh,ww);
		}
	}
}

int main(void)
{
	int t, k, count=0, x, y;
	scanf("%d", &t);
	while(t!=0)
	{
		scanf("%d %d %d", &m, &n, &k);
		for(int i=0; i<k; i++)
		{
			scanf("%d %d", &x, &y);
			map[x][y]=1;
		}
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(map[i][j]==1)
				{
					count++;
					DFS(i,j);
				}
			}
		}
		printf("%d\n", count);
		count=0;
		
		t--;
	}
	
	return 0;
}