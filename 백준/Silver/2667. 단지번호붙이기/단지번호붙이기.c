#include <stdio.h>

int map[30][30], visit[30][30]={0,};
int n, count;
int d[4]={1,-1,0,0};

void DFS(int h, int w)
{
	int hh, ww;
	count++;
	visit[h][w]=1;
	for(int i=0; i<4; i++)
	{
		if(0<h+d[i]&&h+d[i]<=n&&0<w+d[3-i]&&w+d[3-i]<=n)
		{
			hh = h+d[i];
			ww = w+d[3-i];
			
			if(map[hh][ww]==1&&visit[hh][ww]==0) DFS(hh,ww);
		}
	}
}

int main(void)
{
	int i, j, idx=0;
	int arr[500] = {0,};
	scanf("%d", &n);
	for(i=1; i<=n; i++)
	{
		for(j=1;j<=n; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	for(i=1; i<=n; i++)
	{
		for(j=1;j<=n; j++)
		{
			if(map[i][j]==1&&visit[i][j]==0)
			{
				count=0;
				DFS(i,j);
				arr[idx++]=count;
			}
		}
	}
	
	for(int i=0;i<idx-1;i++)
		for(int j=0;j<idx-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp;
				temp = arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}

	printf("%d\n", idx);
	for(int i=0;i<idx;i++)
		printf("%d\n",arr[i]);
	
	
	
	return 0;
}