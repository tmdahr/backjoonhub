#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

typedef struct _node
{
	int to, cost;
} node;
vector<node> t[100005];

node solution(node from)
{
	int visit[100005]={0,};
	node m, now;
	queue<node> q;
	q.push({from.to,0});
	visit[from.to]=1;
	
	while(!q.empty())
	{
		now = q.front();
		q.pop();
		if(m.cost<now.cost) m = now;
		
		for(int i=0;i<t[now.to].size();i++)
		{
			node next=t[now.to][i];
			if(visit[next.to]!=1)
			{
				visit[now.to]=1;
				q.push({next.to,now.cost+next.cost});
			}
		}
		
	}
	
	return m;
}

int main(void)
{
	int v;
	scanf("%d", &v);
	for(int i=0; i<v; i++)
	{
		int from, to, cost;
		scanf("%d", &from);
		while(1)
		{
			scanf("%d", &to);
			if(to==-1) break;
			scanf("%d", &cost);
			t[from].push_back({to,cost});
		}
	}
	node start = solution({1,0});
	start = solution({start.to,0});
	printf("%d", start.cost);
	
	return 0;
}