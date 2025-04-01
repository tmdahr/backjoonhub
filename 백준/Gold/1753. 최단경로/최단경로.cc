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
vector<node> map[20005];
int dist[20005];
bool visit[20005];

int main(void)
{
	int v,e,k;
	scanf("%d %d %d", &v, &e, &k);
	for(int i=0; i<e; i++)
	{
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		map[from].push_back({to, cost});
	}
	for(int i=1; i<=v; i++)
		dist[i]=2147483647;
	
	pq.push({k,0});
	dist[k]=0;
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
	for(int i=1; i<=v; i++)
		if(dist[i]==2147483647) printf("INF\n");
		else printf("%d\n", dist[i]);
	
	return 0;
}