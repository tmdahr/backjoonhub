#include <stdio.h>
#include <queue>
#include <vector>
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
vector<node> map[805];
int dist[805];
bool visit[805];

void Dijkstra(int n, int start)
{
	for(int i=1; i<=n; i++)
	{
		dist[i]=2147483647;
		visit[i]=false;
	}
	pq.push({start,0});
	dist[start]=0;
	while(!pq.empty())
	{
		node now = pq.top();
		pq.pop();
		if(visit[now.to]==true) continue;
		else visit[now.to] = true;
		for(int i=0; i<map[now.to].size(); i++)
		{
			int next = map[now.to][i].to;
			int cost = map[now.to][i].cost;
			if(dist[next]>cost+now.cost)
			{
				dist[next] = cost+now.cost;
				pq.push({next, cost+now.cost});
			}
		}
	}
}

int main(void)
{
	int n, e, v1, v2;
	scanf("%d %d", &n, &e);
	for(int i=0; i<e; i++)
	{
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		map[from].push_back({to,cost});
		map[to].push_back({from,cost});
	}
	
	scanf("%d %d", &v1, &v2);
	long long cost=0;
	int start=1;
	Dijkstra(n,start);
	long long SA = dist[v1];
	long long SB = dist[v2];
	Dijkstra(n,v1);
	long long AB = dist[v2];
	long long AE = dist[n];
	Dijkstra(n,v2);
	long long BA = dist[v1];
	long long BE = dist[n];
	if(SA+AB+BE < SB+BA+AE) cost = SA+AB+BE;
	else cost = SB+BA+AE;
	if(cost>=2147483647) printf("-1");
	else printf("%lld", cost);
}