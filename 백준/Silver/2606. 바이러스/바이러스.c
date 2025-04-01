#include <stdio.h>

int map[102][102] = {0, };
int visit[102] = {0, };
int N, M, count=0;

void DFS(int v)
{
	visit[v]=1;
	for(int i=1; i<=N; i++)
	{
		if(map[v][i]==1&&visit[i]==0)
		{
			count++;
			DFS(i);
		}
	}
}

int main(void)
{
	int from, to;
	
	scanf("%d", &N);
	scanf("%d", &M);
	for(int i=0; i<M; i++)
	{
		scanf("%d %d", &from, &to);
		map[from][to]=1;
		map[to][from]=1;
	}
	
	DFS(1);
	printf("%d", count);
	
	return 0;
}