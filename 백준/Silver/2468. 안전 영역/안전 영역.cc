#include <stdio.h>
#include <queue>
using namespace std;

typedef struct _node
{
	int h,w;
} node;
queue<node> q;

int N, mi=101, ma=0, count, mc=0;
int map[105][105], visit[105][105]={0,};
int dh[4]={1,-1,0,0}, dw[4]={0,0,1,-1};

void BFS()
{
	while(!q.empty())
	{
		node now = q.front();
		q.pop();
		
		for(int i=0; i<4; i++)
		{
			int hh=now.h+dh[i];
			int ww=now.w+dw[i];
			if(0<=hh&&hh<N && 0<=ww&&ww<N)
			{
				if(map[hh][ww]>mi && visit[hh][ww]==0)
				{
					visit[hh][ww]=1;
					q.push({hh,ww});
				}
			}
		}
	}
}

int main(void)
{
	int i, j;
	
	scanf("%d", &N);
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
		{
			scanf("%d", &map[i][j]);
			if(mi>map[i][j]) mi = map[i][j];
			if(ma<map[i][j]) ma = map[i][j];
		}
	
	for(mi=mi-1; mi<ma; mi++)
	{
		count=0;
		for(i=0; i<N; i++)
			for(j=0; j<N; j++)
			{
				if(map[i][j]>mi&&visit[i][j]==0)
				{
					count++;
					visit[i][j]=1;
					q.push({i,j});
					BFS();
				}
			}
		if(mc<count) mc = count;
		for(i=0; i<N; i++)
			for(j=0; j<N; j++)
				visit[i][j]=0;
	}
	
	printf("%d\n", mc);
	return 0;
}