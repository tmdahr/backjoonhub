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
vector<node> map[1005];
int dist[1005];
bool visit[1005];

int main(void)
{
	int n, m, start, end;
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++)
	{
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		map[from].push_back({to,cost});
	}
	for(int i=1; i<=n; i++) dist[i]=2147483647;
	
	scanf("%d %d", &start, &end);
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
	printf("%d", dist[end]);
	
	return 0;
}