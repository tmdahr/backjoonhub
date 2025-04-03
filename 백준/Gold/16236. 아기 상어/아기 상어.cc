#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct _node
{
	int h,w,cost;
} node;
typedef struct _shark
{
	int h, w, size, fish;
} shark;
bool com(node a, node b)
{
	if(a.cost==b.cost)
	{
		if(a.h==b.h)
		{
			return a.w<b.w;
		}
		else return a.h<b.h;
	}
	else return a.cost<b.cost;
}
node fish[405];
shark sh;
queue<node> q;
int map[25][25], visit[25][25];
int dh[]={1,-1,0,0}, dw[]={0,0,1,-1};
int n, l, sec=0;

void BFS()
{
	l=0;
	while(!q.empty())
	{
		node now = q.front();
		q.pop();
		for(int i=0; i<4; i++)
		{
			int hh = now.h+dh[i];
			int ww = now.w+dw[i];
			if(0<=hh&&hh<n &&0<=ww&&ww<n)
				if(map[hh][ww]<=sh.size && visit[hh][ww]==0)
				{
					if(0<map[hh][ww] && map[hh][ww]<sh.size) fish[l++]={hh,ww,now.cost+1};
					visit[hh][ww]=1;
					q.push({hh,ww,now.cost+1});
				}
		}
	}
}

int main(void)
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			scanf("%d", &map[i][j]);
			if(map[i][j]==9)
			{
				sh={i,j,2,0};
				q.push({i,j,0});
				map[i][j]=0;
			}
		}
	BFS();
	while(l>0)
	{
		sort(fish,fish+l,com);
		sec+=fish[0].cost;
		sh={fish[0].h,fish[0].w,sh.size,sh.fish+1};
		if(sh.fish==sh.size)
		{
			sh.fish=0;
			sh.size++;
		}
		map[sh.h][sh.w]=0;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++) visit[i][j]=0;
		q.push({sh.h,sh.w,0});
		BFS();
	}
	printf("%d", sec);
}