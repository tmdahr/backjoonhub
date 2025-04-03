#include <stdio.h>
#include <queue>
using namespace std;

typedef struct _node
{
	int h,n,m,count;
} node;
queue<node> q;

int M, N, H, C=0;
int map[105][105][105], visit[105][105][105]={0,};
int dh[6]={1,-1,0,0,0,0}, dn[6]={0,0,1,-1,0,0}, dm[6]={0,0,0,0,1,-1};

void BFS()
{
	
	while(!q.empty())
	{
		node now = q.front();
		q.pop();
		
		for(int i=0; i<6; i++)
		{
			int hh=now.h+dh[i];
			int nn=now.n+dn[i];
			int mm=now.m+dm[i];
			if(0<=hh&&hh<H && 0<=nn&&nn<N && 0<=mm&&mm<M)
			{
				if(map[hh][nn][mm]==0 && visit[hh][nn][mm]==0)
				{
					q.push({hh,nn,mm,now.count+1});
					visit[hh][nn][mm]=1;
					map[hh][nn][mm]=1;
					if(C<now.count) C = now.count;
				}
			}
		}
	}
}

int main(void)
{
	int i, j, l, o=0;
	scanf("%d %d %d", &M, &N, &H);
	
	for(i=0; i<H; i++)
		for(j=0; j<N; j++)
			for(l=0; l<M; l++)
			{
				scanf("%d", &map[i][j][l]);
				if(map[i][j][l]==1)
				{
					q.push({i,j,l,1});
					visit[i][j][l]=1;
				}
			}
	BFS();
	
	for(i=0; i<H; i++)
		for(j=0; j<N; j++)
			for(l=0; l<M; l++)
				if(map[i][j][l]==0) o++;
				
	if(o==0) printf("%d\n", C);
	else printf("-1\n");
	
	return 0;
}