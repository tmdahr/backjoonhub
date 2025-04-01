#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct _node
{
	int y, x;
} node;
queue<node> q;

int map[105][105]={0,}, visit[105][105]={0,};
int M, N, K;
int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};

void BFS(int area)
{
	while(!q.empty())
	{
		node now = q.front();
		q.pop();
		
		for(int i=0; i<4; i++)
		{
			int xx = now.x+dx[i];
			int yy = now.y+dy[i];
			if(0<=xx&&xx<N && 0<=yy&&yy<M)
				if(map[yy][xx]==0 && visit[yy][xx]==0)
				{
					visit[yy][xx] = area;
					q.push({yy,xx});
				}
		}
	}
}

int main(void)
{
	int lx, ly, rx, ry, i, j, count=0, l;
	int p[7000]={0};
	scanf("%d %d %d", &M, &N, &K);
	for(l=0;l<K;l++)
	{
		scanf("%d %d %d %d", &lx, &ly, &rx, &ry);
		for(i=0; i<ry-ly; i++)
			for(j=0; j<rx-lx; j++)
				map[ly+i][lx+j]=-1;
	}
	
	for(i=0; i<M; i++)
		for(j=0; j<N; j++)
			if(map[i][j]==0 && visit[i][j]==0)
			{
				count++;
				visit[i][j] = count;
				q.push({i,j});
				BFS(count);
			}
	
	for(i=0; i<M; i++)
		for(j=0; j<N; j++)
			p[visit[i][j]]++;
	sort(p+1, p+count+1);
	printf("%d\n", count);
	for(i=1; i<=count; i++) printf("%d ", p[i]);
	/*puts("");
	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
			printf("%3d ", map[i][j]);
		puts("");
	}
	for(i=0; i<=M; i++)
	{
		for(j=0; j<N; j++)
			printf("%3d ", visit[i][j]);
		puts("");
	}*/
	
	return 0;
}