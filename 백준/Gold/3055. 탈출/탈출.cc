#include <stdio.h>
#include <queue>
using namespace std;

typedef struct _node
{
	int r, c;
} node;
int r, c, count;
int dr[]={1,-1,0,0}, dc[]={0,0,1,-1};
char map[55][55];
int visit[55][55];
node d;
queue<node> water, s;

void flood()
{
	int len = water.size();
	for(int j=0; j<len; j++)
	{
		node now = water.front();
		water.pop();
		for(int i=0; i<4; i++)
		{
			int rr = now.r+dr[i];
			int cc = now.c+dc[i];
			if(visit[rr][cc]==0 && 0<=rr&&rr<r && 0<=cc&&cc<c)
			{
				visit[rr][cc]=1;
				water.push({rr,cc});
			}
		}
	}
}

bool move()
{
	count++;
	int len = s.size();
	for(int j=0; j<len; j++)
	{
		node now = s.front();
		s.pop();
		for(int i=0; i<4; i++)
		{
			int rr = now.r+dr[i];
			int cc = now.c+dc[i];
			if(rr==d.r && cc==d.c)
			{
				printf("%d", count);
				return true;
			}
			if(visit[rr][cc]==0 && 0<=rr&&rr<r && 0<=cc&&cc<c)
			{
				visit[rr][cc]=1;
				s.push({rr,cc});
			}
		}
	}
	if(s.empty())
	{
		printf("KAKTUS");
		return true;
	}
	else return false;
}

int main(void)
{
	scanf("%d %d", &r, &c);
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
		{
			scanf(" %c", &map[i][j]);
			if(map[i][j]!='.') visit[i][j]=1;
			if(map[i][j]=='D') d = {i,j};
			else if(map[i][j]=='S') s.push({i,j});
			else if(map[i][j]=='*') water.push({i,j});
		}
	while(1)
	{
		flood();
		if(move()) break;
	}
	
	return 0;
}