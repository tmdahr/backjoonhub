#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef struct _node
{
	int from, to, cost;
} node;
typedef struct _que
{
	int h,w;
} que;
int parent[105], dh[4]={1,-1,0,0}, dw[4]={0,0,1,-1};
int map[15][15], visit[15][15];
int num=1;

int find(int v)
{
	if(parent[v]==v) return v;
	else return parent[v] = find(parent[v]);
}
bool cmp(node a, node b)
{
	return a.cost<b.cost;
}

void BFS(int n, int m, int h, int w)
{
	queue<que> q;
	q.push({h,w});
	map[h][w]=++num;
	visit[h][w]=1;
	
	while(!q.empty())
	{
		que now = q.front();
		q.pop();
		for(int i=0; i<4; i++)
		{
			int hh = now.h+dh[i];
			int ww = now.w+dw[i];
			if(0<=hh&&hh<n && 0<=ww&&ww<m)
				if(map[hh][ww]!=0 && visit[hh][ww]==0)
				{
					visit[hh][ww]=1;
					map[hh][ww]=num;
					q.push({hh,ww});
				}
		}
	}
}

int main(void)
{
	vector<node> land;
	int n,m, i,j, res=0, d;
	
	scanf("%d %d", &n, &m);
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
			scanf("%d", &map[i][j]);
	for(i=0; i<=6; i++) parent[i]=i;
	
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
			if(map[i][j]==1) BFS(n,m,i,j);
		

		
		
	
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			if(map[i][j]!=0)
			{
				int h = i;
				int w = j;
				for(int k=0;k<4;k++)
				{
					int hh=h,ww=w;
					int dist=0;
					while(1)
					{
						dist++;
						hh = hh+dh[k];
						ww = ww+dw[k];						
						if(!(0<=hh&&hh<n && 0<=ww&&ww<m))
							break;
						if(map[hh][ww]==map[h][w])
							break;
						if(map[hh][ww]!=map[h][w] && map[hh][ww]>0)
						{
							land.push_back({map[h][w],map[hh][ww],dist-1});
							break;
						}
					}
				}
				
			}
	
	sort(land.begin(),land.end(),cmp);
	
	for(i=0; i<land.size(); i++)
	{
		if(land[i].cost<2)
			continue;
		int a=find(land[i].from);
		int b=find(land[i].to);
		if(a==b) continue;
		if(a<b) parent[a]=b;
		else parent[b]=a;
		res+=land[i].cost;
	}
	int prev = find(2);
	for(int i=3;i<=num;i++)
	{
		if(prev!=find(i))
			res = -1;
	}
	printf("%d", res);
	
	return 0;
}