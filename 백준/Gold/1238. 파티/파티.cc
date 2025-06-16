#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

typedef struct
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
vector<node> map[1005];
int dist[1005], visit[1005], go[1005], turn[1005];

int main(void)
{
	int n, m, x, max=0;
	scanf("%d %d %d", &n, &m, &x);
	for(int i=0; i<m; i++)
	{
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		map[from].push_back({to,cost});
	}
	for(int i=1; i<=n; i++)
	{
		priority_queue<node, vector<node>, cmp> pq;
		for(int j=1; j<=n; j++)
		{
			dist[j] = 2147483647;
			visit[j] = 0;
		}
		pq.push({i,0});
		dist[i]=0;
		while(!pq.empty())
		{
			node now = pq.top();
			pq.pop();
			if(visit[now.to]==true) continue;
			else visit[now.to]=true;
			for(int j=0; j<map[now.to].size(); j++)
			{
				int next = map[now.to][j].to;
				int cost = map[now.to][j].cost;
				if(dist[next]>now.cost+cost)
				{
					dist[next] = now.cost+cost;
					pq.push({next, dist[next]});
				}
			}
		}
		if(i==x)
		{
			for(int j=1; j<=n; j++)
			{
				turn[j] = dist[j];
			}
		}
		else go[i] = dist[x];
	}
	for(int i=1; i<=n; i++)
	{
		if(max<go[i]+turn[i]) max = go[i]+turn[i];
	}
	printf("%d\n", max);
	return 0;
}