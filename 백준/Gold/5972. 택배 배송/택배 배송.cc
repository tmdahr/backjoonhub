#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

typedef struct _node
{
	int to, cost;
} node;

struct cmp
{
	bool operator()(node a, node b)
	{
		return a.cost>b.cost;
	}
};
priority_queue<node, vector<node>, cmp> pq;
vector<node> map[500005];
int dist[500005], visit[500005];
int n,m;

int main(void)
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++)
	{
		int f,t,c;
		scanf("%d %d %d", &f, &t, &c);
		map[f].push_back({t,c});
		map[t].push_back({f,c});
	}
	for(int i=1; i<=n; i++) dist[i]=2147483647;
	
	pq.push({1,0});
	dist[1]=0;
	while(!pq.empty())
	{
		node now = pq.top();
		pq.pop();
		if(visit[now.to]==1) continue;
		visit[now.to]=1;
		
		for(int i=0; i<map[now.to].size(); i++)
		{
			int next=map[now.to][i].to;
			int cost=map[now.to][i].cost;
			if(dist[next]>cost+now.cost)
			{
				dist[next] = cost+now.cost;
				pq.push({next, cost+now.cost});
			}
		}
	}
	
	printf("%d", dist[n]);
	return 0;
}