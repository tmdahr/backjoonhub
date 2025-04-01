#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef struct _node
{
	int h,w,cost;
} node;
int n,m;
int map[105][105],visit[105][105],dist[105][105];
int dh[]={1,-1,0,0}, dw[]={0,0,1,-1};
struct cmp
{
	bool operator()(node a, node b)
	{
		return a.cost>b.cost;
	}
};

void dijkstra()
{
	dist[0][0]=0;
	priority_queue <node, vector<node>, cmp> pq;
	pq.push({0,0,0});
	
	while(!pq.empty())
	{
		node now = pq.top();
		pq.pop();
		if(visit[now.h][now.w]==1) continue;
		else visit[now.h][now.w]=1;
		
		for(int i=0; i<4; i++)
		{
			int hh=now.h+dh[i];
			int ww=now.w+dw[i];
			if(0<=hh&&hh<n && 0<=ww&&ww<m)
			{
				if(dist[hh][ww]>dist[now.h][now.w]+map[hh][ww])
				{
					dist[hh][ww]=dist[now.h][now.w]+map[hh][ww];
					pq.push({hh,ww,dist[hh][ww]});
				}
			}
		}
	}
}

int main(void)
{
	scanf("%d %d", &m, &n);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		{
			scanf("%1d", &map[i][j]);
			dist[i][j]=2147483647;
		}
	dijkstra();
	printf("%d", dist[n-1][m-1]);
}