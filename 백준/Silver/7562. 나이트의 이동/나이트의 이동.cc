#include <stdio.h>
#include <queue>
using namespace std;

int map[305][305],visit[305][305];
int count, i;
typedef struct _node
{
	int h,w;
	int cnt;
} node;
node t;


int c, l, j;

int BFS()
{
	int dh[8]={-1,-2,-2,-1,1,2,2,1};
	int dw[8]={-2,-1,1,2,2,1,-1,-2};
	
	queue<node> q;
	
	q.push({l,j,0});
	
	visit[l][j]=1;
	
	while(!q.empty())
	{
		node now = q.front();
		q.pop();
		
		if(now.h==t.h && now.w==t.w)
			return now.cnt;
		
		for(int j=0; j<8; j++)
		{
			int hh = now.h+dh[j];
			int ww = now.w+dw[j];
			if(0<=hh&&hh<i&&0<=ww&&ww<i)
			{
				if(visit[hh][ww]==0)
				{
					q.push({hh,ww,now.cnt+1});
					visit[hh][ww]=1;
				}
			}
		}
	}
	
}
void init()
{
	for(l=0; l<i; l++)
	{
		for(j=0; j<i; j++)
		{
			map[l][j]=0;
			visit[l][j]=0;
		}
	}
}
int main(void)
{
	
	scanf("%d", &c);
	while(c--)
	{
		scanf("%d", &i);
		init();
		scanf("%d %d", &l, &j);
		scanf("%d %d", &t.h, &t.w);
		
		printf("%d\n", BFS());
	}
}