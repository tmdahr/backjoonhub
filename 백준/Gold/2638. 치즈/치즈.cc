#include <stdio.h>
#include <queue>
using namespace std;
typedef struct _node
{
	int h,w;
} node;
queue<node> q;
node s,e;
int map[105][105], visit[105][105], test[105][105];
int dh[4]={1,-1,0,0}, dw[4]={0,0,1,-1};
int n,m,sec=0;

void DFS(int h, int w)
{
	visit[h][w]=1;
	for(int i=0; i<4; i++)
	{
		int hh=h+dh[i];
		int ww=w+dw[i];
		if(0<=hh&&hh<n && 0<=ww&&ww<m &&visit[hh][ww]==0)
		{
			if(map[hh][ww]==0||map[hh][ww]==2)
			{
				test[hh][ww]=2;
				DFS(hh,ww);
			}
		}
	}
}

void BFS()
{
	while(!q.empty())
	{
		node now = q.front();
		q.pop();
		int air=0;
		for(int i=0; i<4; i++)
		{
			int hh=now.h+dh[i];
			int ww=now.w+dw[i];
			if(0<=hh&&hh<n && 0<=ww&&ww<m && test[hh][ww]==2)
			{
				air++;
				if(air>=2)
				{
					map[now.h][now.w]=2;
					break;
				}
			}
		}
	}
}

int main(void)
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		{
			scanf("%d", &map[i][j]);
			test[i][j] = map[i][j];
		}
	
	while(1)
	{
		DFS(0,0);
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				visit[i][j]=0;
				if(map[i][j]==1) q.push({i,j});
			}
		}
		if(q.empty()) break;
		BFS();
		sec++;
	}
	printf("%d\n", sec);
}