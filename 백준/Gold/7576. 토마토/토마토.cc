#include <stdio.h>
#include <queue>
using namespace std;

int box[1005][1005]={ 00,};
int visit[1005][1005];
int n, m, count=0, o=0;

typedef struct _node
{
	int h,w; 
} node;
queue<node> q; 

void BFS()
{
	int d[4] = {1,-1,0,0};
	while(!q.empty())
	{
		node now = q.front();
		q.pop();
		
		for(int j=0; j<4; j++)
		{
			int hh=now.h+d[j];
			int ww=now.w+d[3-j];
			if(1<=hh&&hh<=n && 1<=ww&&ww<=m)
			{
				if(box[hh][ww]==0 && visit[hh][ww]==0)
				{
					q.push({hh,ww});	
					visit[hh][ww]=visit[now.h][now.w]+1;
					if(count<visit[hh][ww]-1) count = visit[hh][ww]-1;
				}
			}
		}
	}
}

int main(void)
{
	int i, j;
	scanf("%d %d", &m, &n);//n 세로 m 가로
	
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=m; j++)
		{
			scanf("%d", &box[i][j]);//i 세로 j 가로
			if(box[i][j]==1)
			{
				q.push({i,j});	
				visit[i][j]=1;
			} 
		}
	}
	BFS();
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=m; j++)
		{
			if(visit[i][j]==0&&box[i][j]!=-1) o++;
		}
	}
	if(o==0) printf("%d\n", count);
	else printf("-1\n");
}