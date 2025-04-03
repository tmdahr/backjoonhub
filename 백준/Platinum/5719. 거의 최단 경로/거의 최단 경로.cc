#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

typedef struct _node
{
	int to,cost;
} node;
struct cmp
{
	bool operator()(node a, node b)
	{
		return a.cost>b.cost;
	}
};
priority_queue<node,vector<node>,cmp> pq;
int map[505][505];
int dist[505];
int n,m,s,d;

void Dijkstra()
{
	bool visit[505]={false};
	for(int i=0; i<n; i++) dist[i] = 2147483647;
	pq.push({s,0});
	dist[s]=0;
	while(!pq.empty())
	{
		node now = pq.top();
		pq.pop();
		if(visit[now.to]==true) continue;
		else visit[now.to] = true;
		for(int i=0; i<n; i++)
		{
			if(map[now.to][i]>0 && dist[i] > dist[now.to]+map[now.to][i])
			{
				dist[i] = dist[now.to]+map[now.to][i];
				pq.push({i, dist[i]});
			}
		}
	}
}

void bfs()
{
	queue<int> q;
	q.push(d);
	
	while(!q.empty())
	{
		int next = q.front();
		q.pop();
		for(int now=0; now<n; now++)
		{
			if(map[now][next]>0&&dist[next]==dist[now]+map[now][next])
			{
				q.push(now);
				map[now][next]=0;
			}
		}
	}
}

int main(void)
{
	while(1)
	{
		scanf("%d %d", &n, &m);
		if(n==0&&m==0) break;
		scanf("%d %d", &s, &d);
		for(int i=0; i<m; i++)
		{
			int from, to, cost;
			scanf("%d %d %d", &from, &to, &cost);
			map[from][to] = cost;
		}
		
		Dijkstra();
		bfs();
		Dijkstra();
		if(dist[d]==2147483647) printf("-1\n");
		else printf("%d\n", dist[d]);
		for(int i=0; i<n; i++)
			for(int j=0; j<500; j++)
				map[i][j]=0;
	}
}