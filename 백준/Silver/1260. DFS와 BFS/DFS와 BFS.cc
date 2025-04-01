#include <stdio.h>
#include <queue>
using namespace std;

int map[1005][1005];
int visit[1005];
int N, M, V;

void init()
{
	for(int i=1; i<=N; i++) visit[i]=0;
}

void DFS(int v)
{
	visit[v]=1;
	printf("%d ", v);
	for(int i=1; i<=N; i++)
	{
		if(map[v][i]==1&&visit[i]==0)
		{
			DFS(i);
		}
	}
}

void BFS(int v)
{
	queue<int> q;
	q.push(v);
	visit[v]=1;
	
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		printf("%d ", now);
		for(int i=1; i<=N; i++)
		{
			if(map[now][i]==1&&visit[i]==0)
			{
				q.push(i);
				visit[i]=1;
			}
		}
	}
}

int main(void)
{
	scanf("%d %d %d", &N, &M, &V);
	int from, to;
	for(int i=0; i<M; i++)
	{
		scanf("%d %d", &from, &to);
		map[from][to]=1;
		map[to][from]=1;
	}
	
	DFS(V);
	printf("\n");
	init();
	BFS(V);
	
	return 0;
}