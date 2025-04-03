#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

typedef struct _node
{
	int h,w;
} node;
int n,m,cnt=0;
int d[4]={1,-1,0,0};
int map[10][10], cm[10][10];
queue<node> v;

void back(int wall)
{
	if(wall==3)
	{
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
			{
				cm[i][j] = map[i][j];
				if(map[i][j]==2) v.push({i,j});
			}
		while(!v.empty())
		{
			node sp = v.front();
			v.pop();
			for(int i=0; i<4; i++)
			{
				int h = sp.h+d[i];
				int w = sp.w+d[3-i];
				if(0<=h&&h<n&&0<=w&&w<m && cm[h][w]==0)
				{
					cm[h][w]=2;
					v.push({h,w});
				}
			}
		}
		int c=0;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(cm[i][j]==0) c++;
		if(cnt<c) cnt = c;
	}
	else
	{
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(map[i][j]==0)
				{
					map[i][j]=1;
					back(wall+1);
					map[i][j]=0;
				}
	}
	
	return ;
}

int main(void)
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			scanf("%d", &map[i][j]);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		{
			if(map[i][j]==0)
			{
				map[i][j]=1;
				back(1);
				map[i][j]=0;
			}
		}
	printf("%d", cnt);
	
	return 0;
}