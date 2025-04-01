#include <stdio.h>
#include <queue>
using namespace std;

typedef struct _node
{
	int r, c;
} node;
int r, c;
int dr[]={1,-1,0,0}, dc[]={0,0,1,-1};
int visit[105][105];
char map[105][105];

void bfs(int nr, int nc)
{
	queue<node> q;
	q.push({nr, nc});
	visit[nr][nc]=1;
	while(!q.empty())
	{
		node now = q.front();
		q.pop();
		for(int i=0; i<4; i++)
		{
			int rr = now.r+dr[i];
			int cc = now.c+dc[i];
			if(0<=rr&&rr<r&&0<=cc&&cc<c &&visit[rr][cc]==0&&map[rr][cc]=='x')
			{
				visit[rr][cc]=1;
				q.push({rr,cc});
			}
		}
	}
}

void move()
{
	queue<node> q;
	for(int i=r-1; i>=0; i--)
		for(int j=0; j<c; j++)
			if(visit[i][j]==0 && map[i][j]=='x') q.push({i,j});
	int len = q.size();
	if(len==0) return;
	bool l = true;
	while(l)
	{
		for(int i=0; i<len; i++)
		{
			node now = q.front();
			q.pop();
			map[now.r+1][now.c] = 'x';
			map[now.r][now.c] = '.';
			if(visit[now.r+2][now.c]==1 || now.r+2==r) l = false;
			q.push({now.r+1, now.c});
		}
	}
}

int main(void)
{
	scanf("%d %d",&r,&c);
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			scanf(" %c", &map[i][j]);
	
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int st;
		scanf("%d", &st);
		if(i%2==0)
		{
			for(int j=0; j<c; j++)
				if(map[r-st][j]=='x')
				{
					map[r-st][j]='.';
					break;
				}
		}	
		else
		{
			for(int j=c-1; j>=0; j--)
					if(map[r-st][j]=='x')
					{
						map[r-st][j]='.';
						break;
					}	
		}
		for(int i=0; i<r; i++)
			for(int j=0; j<c; j++)
				visit[i][j]=0;
		for(int j=0; j<c; j++)
			if(map[r-1][j]=='x')
				bfs(r-1,j);
		move();
	}
	for(int i=0; i<r; i++)
		{
			for(int j=0; j<c; j++) printf("%c", map[i][j]);
			printf("\n");
		}
	return 0;
}