#include <stdio.h>
#include <queue>
using namespace std;
typedef struct _node
{
	int h, w;
} node;
queue<node> q;
int map[305][305], test[305][305], visit[305][305];
int dh[4]={1,-1,0,0}, dw[4]={0,0,1,-1};
int n, m, count=1, y=0;

void BFS()
{
	while(!q.empty())
	{
		node now = q.front();
		q.pop();
		for(int i=0; i<4; i++)
		{
			int hh = now.h+dh[i];
			int ww = now.w+dw[i];
			if(0<=hh&&hh<n && 0<=ww&&ww<m)
				if(test[hh][ww]>0 && visit[hh][ww]==0)
				{
					visit[hh][ww]=1;
					q.push({hh,ww});
				}
		}
	}
}

void year(int h, int w)
{
	for(int i=0; i<4; i++)
	{
		int hh=h+dh[i];
		int ww=w+dw[i];
		if(0<=hh&&hh<n && 0<=ww&&ww<m)
			if(map[hh][ww]<=0) test[h][w]--;
	}
}

int main(void)
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		{
			scanf("%d", &map[i][j]);
			test[i][j]=map[i][j];
		}
	
	while(count==1)
	{
		y++;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
			{
				visit[i][j]=0;
				if(test[i][j]>0) year(i,j);
			}
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(map[i][j]>0) map[i][j] = test[i][j];
			
		count=0;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
			{
				if(test[i][j]>0 && visit[i][j]==0)
				{
					count++;
					q.push({i,j});
					visit[i][j]=1;
					BFS();
				}
			}
		if(count==0) printf("0\n");
		else if(count>1) printf("%d\n", y);
	}
}