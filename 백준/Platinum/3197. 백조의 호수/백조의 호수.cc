#include <stdio.h>
#include <queue>
using namespace std;

typedef struct _node
{
	int r,c;
} node;
typedef struct _nod
{
	int r,c,n;
} nod;
int r,c;
node sw1, sw2;
int parent[1500*1500+5];
bool visit[1505][1505];
int area[1505][1505];
int dr[]={1,-1,0,0}, dc[]={0,0,1,-1};

int find(int v)
{
	if(parent[v]==v) return v;
	else return parent[v]=find(parent[v]);
}
void merge(int v, int u)
{
	v = find(v);
	u = find(u);
	if(v!=u) parent[v]=u;
}

void bfs(int nr, int nc, int n)
{
	queue<node> q;
	q.push({nr, nc});
	visit[nr][nc]=true;
	area[nr][nc]=n;
	while(!q.empty())
	{
		node now = q.front();
		q.pop();
		for(int i=0; i<4; i++)
		{
			int rr = now.r+dr[i];
			int cc = now.c+dc[i];
			if(0<=rr&&rr<r && 0<=cc&&cc<c)
				if(visit[rr][cc]==false&&area[rr][cc]==0)
				{
					visit[rr][cc]=true;
					area[rr][cc]=n;
					q.push({rr,cc});
				}
		}
	}
}

int solution()
{
	int s1=area[sw1.r][sw1.c];
	int s2=area[sw2.r][sw2.c];
	queue<nod> q;
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			if(area[i][j]!=-1)
				for(int d=0; d<4; d++)
				{
					int rr = i+dr[d];
					int cc = j+dc[d];
					if(0<=rr&&rr<r && 0<=cc&&cc<c)
						if(visit[rr][cc]==false&&area[rr][cc]==-1)
						{
							visit[rr][cc]=true;
							q.push({rr,cc,area[i][j]});
						}
				}
	int day=0;
	while(!q.empty())
	{
		day++;
		int size = q.size();
		for(int i=0; i<size; i++)
		{
			nod now = q.front();
			q.pop();
			area[now.r][now.c]=now.n;
			for(int j=0; j<4; j++)
			{
				int rr = now.r+dr[j];
				int cc = now.c+dc[j];
				if(0<=rr&&rr<r && 0<=cc&&cc<c)
				{
					if(visit[rr][cc]==true)
					{
						if(area[rr][cc]==-1) continue;
						else merge(now.n,area[rr][cc]);
					}
					else
					{
						visit[rr][cc]=true;
						q.push({rr,cc,now.n});
					}
				}
			}
			if(find(s1)==find(s2)) return day;
		}
	}
}

int main(void)
{
	int n=0;
	char map;
	scanf("%d %d",&r,&c);
	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
		{
			scanf(" %c", &map);
			if(map=='X') area[i][j]=-1;
			else if(map=='L')
			{
				if(n==0) sw1={i,j};
				else sw2={i,j};
				n++;
			}
		}
	}
	n=0;
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			if(visit[i][j]==false&&area[i][j]==0)
				bfs(i,j,++n);
	for(int i=0; i<=n; i++) parent[i]=i;
	printf("%d", solution());
	
	return 0;
}