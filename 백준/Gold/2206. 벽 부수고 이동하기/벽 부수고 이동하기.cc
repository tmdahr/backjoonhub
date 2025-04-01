#include <stdio.h>
#include <queue>
using namespace std;

typedef struct _node
{
	int h, w, c, d;
} node;
queue<node> q;

int n, m;
int visit[1005][1005][3];
int map[1005][1005];
int dh[4]={1,-1,0,0}, dw[4]={0,0,1,-1};

int BFS()
{
	while(!q.empty())
	{
		node now = q.front();
		q.pop();
		
		if(now.h==n&&now.w==m) return now.c;
		
		for(int i=0; i<4; i++)
		{
			int hh = now.h+dh[i];
			int ww = now.w+dw[i];
			if(1<=hh&&hh<=n && 1<=ww&&ww<=m)
				if(visit[hh][ww][now.d]==0)
				{
					if(map[hh][ww]==0)
					{
						q.push({hh,ww,now.c+1,now.d});
						visit[hh][ww][now.d]=1;
					}
					else if(now.d>0)
					{
						q.push({hh,ww,now.c+1,now.d-1});
						visit[hh][ww][now.d-1]=1;
					}
				}	
		}
	}
	return -1;
}

int main(void)
{
	scanf("%d %d", &n, &m);
	
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			scanf("%1d", &map[i][j]);
	q.push({1,1,1,1});
	visit[1][1][1]=1;
	printf("%d", BFS());
	
	return 0;
}