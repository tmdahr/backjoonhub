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
struct cmpt
{
	bool operator()(int a, int b)
	{
		return a<b;
	}
};
priority_queue<node, vector<node>, cmp> pq;
vector<node> map[10005];
priority_queue<int, vector<int>, cmpt> dist[10005];
int n,m,k;

void Dijkstra()
{
	pq.push({1,0});
	dist[1].push(0);
	while(!pq.empty())
	{
		node now=pq.top();
		pq.pop();
		for(int i=0; i<map[now.to].size(); i++)
		{
			int next=map[now.to][i].to;
			int cost=now.cost+map[now.to][i].cost;
			if(dist[next].size()<k)
			{
				dist[next].push(cost);
				pq.push({next,cost});
			}
			else
			{
				if(dist[next].top()>cost)
				{
					dist[next].pop();
					dist[next].push(cost);
					pq.push({next,cost});
				}
			}
		}
	}
}

int main(void)
{
	scanf("%d %d %d", &n, &m, &k);
	for(int i=0; i<m; i++)
	{
		int f,t,c;
		scanf("%d %d %d", &f, &t, &c);
		map[f].push_back({t,c});
	}
	Dijkstra();
	for(int i=1; i<=n; i++)
	{
		if(dist[i].size()<k) printf("-1\n");
		else printf("%d\n", dist[i].top());
	}
	return 0;
}