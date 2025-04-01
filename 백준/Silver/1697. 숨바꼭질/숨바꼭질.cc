#include <stdio.h>
#include <queue>
using namespace std;

typedef struct _node
{
	int x, s;
} node;

int BFS(int n, int k)
{
	int visit[100005]={0,};
	queue<node> q;
	q.push({n,0});
	while(!q.empty())
	{
		node now = q.front();
		q.pop();
		if(now.x==k) return now.s;
		if(now.x>0 && visit[now.x-1]==0)
		{
			q.push({now.x-1,now.s+1});
			visit[now.x-1]++;
		}
		if(now.x<100000 && visit[now.x+1]==0)
		{
			q.push({now.x+1,now.s+1});
			visit[now.x+1]++;
		}
		if(now.x<=50000 && visit[now.x*2]==0)
		{
			q.push({now.x*2,now.s+1});
			visit[now.x*2]++;
		}
	}
}

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);
	int s = BFS(n, k);
	printf("%d", s);
	return 0;
}