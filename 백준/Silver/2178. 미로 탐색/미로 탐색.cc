#include <stdio.h>
#include <queue>
using namespace std;

typedef struct _node
{
	int h, w;
} node;
int map[102][102] = {0, };
int visit[102][102] = {0, };
int dh[4] = {0,0,1,-1};
int dw[4] = {1,-1,0,0};
int N, M;

int BFS()
{
	queue<node> q;
	q.push({1,1});
	visit[1][1]=1;
	
	while(!q.empty())
	{
		node now = q.front();
		q.pop();
		if(now.h==N&&now.w==M) return visit[N][M];
		for(int i=0; i<4; i++)
		{
			int hh = now.h + dh[i];
			int ww = now.w + dw[i];
			if(1<=hh&&hh<=N&&1<=ww&&ww<=M)
			{
				if(map[hh][ww]==1&&visit[hh][ww]==0)
				{
					q.push({hh, ww});
					visit[hh][ww]=visit[now.h][now.w]+1;
				}
			}
		}
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++)
	{
		for(int l=1; l<=M; l++)
		{
			scanf("%1d", &map[i][l]);
		}
	}
	printf("%d", BFS());
	return 0;
}