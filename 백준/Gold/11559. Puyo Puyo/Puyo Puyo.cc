#include <stdio.h>
#include <queue>
using namespace std;

typedef struct _node
{
	int h, r;
} node;
int map[15][10], visit[15][10];


bool bfs(int h, int r, int n)
{
	int dh[]={1,-1,0,0}, dr[]={0,0,1,-1};
	queue<node> q, p;
	
	q.push({h,r});
	visit[h][r]=1;
	p.push({h,r});
	while(!q.empty())
	{
		node now = q.front();
		q.pop();
		for(int i=0; i<4; i++)
		{
			int hh = now.h+dh[i];
			int rr = now.r+dr[i];
			if(0<=hh&&hh<12 && 0<=rr&&rr<6)
				if(visit[hh][rr]==0 && map[hh][rr]==n)
				{
					q.push({hh,rr});
					visit[hh][rr]=1;
					p.push({hh,rr});
				}
		}
	}
	if(p.size()>=4)
	{
		while(!p.empty())
		{
			node now = p.front();
			p.pop();
			map[now.h][now.r]=0;
		}
		return true;
	}
	else return false;
}

void move()
{
	for(int i=10; i>=0; i--)
		for(int j=0; j<6; j++)
			if(map[i+1][j]==0&&map[i][j]!=0)
			{
				int h = i;
				while(map[h+1][j]==0)
				{
					map[h+1][j] = map[h][j];
					map[h][j]=0;
					h++;
					if(h==11) break;
				}
			}
}

int main(void)
{
	for(int i=0; i<12; i++)
		for(int j=0; j<6; j++)
		{
			char p;
			scanf(" %c", &p);
			if(p!='.')
			{
				if(p=='R') map[i][j]=1;
				else if(p=='G') map[i][j]=2;
				else if(p=='B') map[i][j]=3;
				else if(p=='P') map[i][j]=4;
				else map[i][j]=5;
			} 
		}
	
	int t=0;
	bool l = true;
	while(l)
	{
		l = false;
		for(int i=0; i<12; i++)
			for(int j=0; j<6; j++)
				visit[i][j]=0;
		for(int i=0; i<12; i++)
			for(int j=0; j<6; j++)
			{
				if(visit[i][j]==0 && map[i][j]!=0)
					if(bfs(i,j,map[i][j])) l = true;
			}
		if(l==true)
		{
			t++;
			move();
		}
	}
	printf("%d", t);
	
	return 0;
}