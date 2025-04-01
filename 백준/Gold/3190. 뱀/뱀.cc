#include <stdio.h>
#include <queue>
using namespace std;

typedef struct _turn
{
	int x;
	char c;
} turn;
typedef struct _node
{
	int h, w;
} node;
queue<turn> q;
queue<node> s;
int map[105][105], visit[105][105];
int n;

void snake()
{
	int dh[4]={0,1,0,-1}, dw[4]={1,0,-1,0};
	int time=0, d=0;
	turn t;
	t=q.front();
	q.pop();
	queue<node> last;
	while(!s.empty())
	{
		node now=s.front();
		s.pop();
		last.push({now.h,now.w});
		if(t.x-time==0)
		{
			if(t.c=='L')
			{
				if(d>0) d--;
				else d=3;
			}
			else
			{
				if(d<3) d++;
				else d=0;
			}
			t=q.front();
			q.pop();
		}
		
		int hh=now.h+dh[d];
		int ww=now.w+dw[d];
		if(0<hh&&hh<=n && 0<ww&&ww<=n && visit[hh][ww]==0)
		{
			if(map[hh][ww]==0)
			{
				node l=last.front();
				last.pop();
				visit[l.h][l.w]=0;
			}
			else map[hh][ww]=0;
			
			s.push({hh,ww});
			visit[hh][ww]=1;
			time++;
		}
	}
	printf("%d", time+1);
	return;
}

int main(void)
{
	int k, l;
	scanf("%d", &n);
	scanf("%d", &k);
	for(int i=0; i<k; i++)
	{
		int h,w;
		scanf("%d %d", &h, &w);
		map[h][w]=1;
	}
	scanf("%d", &l);
	for(int i=0; i<l; i++)
	{
		int x;
		char c;
		scanf("%d %c", &x, &c);
		q.push({x,c});
	}
	s.push({1,1});
	visit[1][1]=1;
	snake();
	
	return 0;
}