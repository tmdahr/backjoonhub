#include <stdio.h>
#include <queue>
#include <stack>
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
priority_queue<node, vector<node>, cmp> pq;
vector<node> map[1005];
int dist[1005], parent[1005];

int main(void)
{
	int n, m, start, end;
	scanf("%d", &n);
	scanf("%d", &m);
	for(int i=0; i<m; i++)
	{
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		map[from].push_back({to,cost});
	}
	scanf("%d %d", &start, &end);
	
	for(int i=1; i<=n; i++)
	{
		dist[i] = 2147483647;
		parent[i] = -1;
	}
	pq.push({start,0});
	dist[start] = 0;

	while(!pq.empty())
	{
		node now = pq.top();
		pq.pop();
		if(dist[now.to] < now.cost) continue;
		for(int i=0; i<map[now.to].size(); i++)
		{
			int next = map[now.to][i].to;
			int cost = map[now.to][i].cost;
			if (dist[next] > now.cost+cost)
			{
                dist[next] = now.cost+cost;
                parent[next] = now.to;
                pq.push({next,dist[next]});
            }
		}
	}
	stack<int> road;
	for(int i=end; i!=-1; i=parent[i]) road.push(i);

	printf("%d\n", dist[end]);
	printf("%d\n", road.size());
	while (!road.empty())
	{
        printf("%d ", road.top()); // 경로 출력
        road.pop();
    }

	return 0;
}