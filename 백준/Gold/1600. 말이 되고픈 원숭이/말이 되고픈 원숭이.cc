#include <stdio.h>
#include <queue>
using namespace std;

typedef struct _node{
	int h,w;
	int k;
	int cnt;
}node;

int K,W,H;
int visit[205][205][33];
int map[205][205];
int dh[]={0,0,1,-1};
int dw[]={1,-1,0,0};
int hdw[8]={1,2,2,1,-1,-2,-2,-1}, hdh[8]={2,1,-1,-2,-2,-1,1,2};

int bfs()
{
	queue<node> q;
	q.push({0,0,K,0});
	visit[0][0][K]=1;
	
	while(!q.empty())
	{
		node now = q.front();
		q.pop();
		
		
		if(now.h==H-1 && now.w==W-1)
			return now.cnt;
		
		if(now.k>0)
		{
			for(int i=0;i<8;i++)
			{
				int hh = now.h+hdh[i];
				int ww = now.w+hdw[i];
				
				if(0<=hh&&hh<H && 0<=ww&&ww<W)
				{
					if(map[hh][ww]==0 && visit[hh][ww][now.k-1]==0)
					{
						q.push({hh,ww,now.k-1,now.cnt+1});
						visit[hh][ww][now.k-1]=1;
					}
				}
			}
		}
		
		for(int i=0;i<4;i++)
		{
			int hh = now.h+dh[i];
			int ww = now.w+dw[i];
			
			if(0<=hh&&hh<H && 0<=ww&&ww<W)
			{
				if(map[hh][ww]==0 && visit[hh][ww][now.k]==0)
				{
					q.push({hh,ww,now.k,now.cnt+1});
					visit[hh][ww][now.k]=1;
				}
			}
		}
	}
	
	return -1;
}

int main()
{
	scanf("%d%d%d",&K,&W,&H);
	for(int i=0;i<H;i++)
		for(int j=0;j<W;j++)
			scanf("%d",&map[i][j]);
			
	printf("%d",bfs());
	return 0;
}