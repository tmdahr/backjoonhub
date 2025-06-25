#include <stdio.h>

#define INF 2147483647

int main(void)
{
	int n, m;
	scanf("%d",&n);
	int dist[n+2][n+2];
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			dist[i][j] = (i==j) ? 0 : INF;
	
	scanf("%d",&m);
	for(int i=0; i<m; i++)
	{
		int start, end, cost;
		scanf("%d %d %d", &start, &end, &cost);
		if(cost < dist[start][end]) dist[start][end] = cost;
	}

	for(int k=1; k<=n; k++)
	{
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				if(dist[i][k]<INF && dist[k][j]<INF && dist[i][j] > dist[i][k]+dist[k][j])
				{
					dist[i][j] = dist[i][k]+dist[k][j];
				}
			}
		}
	}
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(dist[i][j]==INF) printf("0 ");
			else printf("%d ", dist[i][j]);
		}
		printf("\n");
	}

	return 0;
}