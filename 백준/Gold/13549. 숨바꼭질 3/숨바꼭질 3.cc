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
priority_queue<node, vector<node>, cmp> pq;
vector<node> map[100005];
int dist[100005], visit[100005];

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i=0; i<=100000; i++) dist[i] = 2147483647;
	pq.push({n,0});
	dist[n] = 0;
	while(!pq.empty())
	{
		node now = pq.top();
		pq.pop();
		if(now.to==k)
		{
			printf("%d\n", dist[k]);
			break;
		}
		if(visit[now.to]==true) continue;
		else visit[now.to]=true;
		if(dist[now.to-1] > now.cost+1)
		{
			dist[now.to-1] = now.cost+1;
			pq.push({now.to-1,now.cost+1});
		}
		if(dist[now.to*2] > now.cost && now.to*2<=100000)
		{
			dist[now.to*2] = now.cost;
			pq.push({now.to*2,now.cost});
		}
		if(dist[now.to+1] > now.cost+1 && now.to+1<=100000)
		{
			dist[now.to+1] = now.cost+1;
			pq.push({now.to+1,now.cost+1});
		}
	}

	return 0;
}