#include <stdio.h>
#include <queue>
using namespace std;

typedef struct _node
{
	int h,w;
} node;
node robot;
queue<node> q;
int map[55][55], visit[55][55];
int dh[]={-1,0,1,0}, dw[]={0,1,0,-1};
int n,m,way,count=0,re;

void DFS(int h, int w)
{
	
	if(map[h][w]==0)
	{
		map[h][w]=2;
		count++;
	}
	for(int i=0; i<4; i++)
	{
		way--;
		if(way<0) way=3;
		int hh=h+dh[way];
		int ww=w+dw[way];
		if(map[hh][ww]==0)
		{
			DFS(hh,ww);
			return;
		}
	}
	re=(way+2)%4;
	int hh=h+dh[re];
	int ww=w+dw[re];
	if(map[hh][ww]!=1) DFS(hh,ww);
}

int main(void)
{
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &robot.h, &robot.w, &way);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			scanf("%d", &map[i][j]);
	DFS(robot.h,robot.w);
	printf("%d", count);
}