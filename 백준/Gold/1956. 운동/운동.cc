#include <stdio.h>
#define INF 2147483647

int main(void)
{
	int v,e;
	scanf("%d %d", &v, &e);
	
	int dist[v+1][v+1];
	for(int i=1; i<=v; i++)
	    for(int j=0; j<=v; j++)
	        dist[i][j]=INF;
	
	for(int i=0; i<e; i++)
	{
	    int a, b, c;
	    scanf("%d %d %d", &a, &b, &c);
	    dist[a][b] = c;
	}
	
	for(int k = 1; k <= v; k++)
        for(int i = 1; i <= v; i++)
            for(int j = 1; j <= v; j++)
                if(dist[i][k] != INF && dist[k][j] != INF)
                    if(dist[i][j] > dist[i][k] + dist[k][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                        
    int min_cycle = INF;
    for(int i = 1; i <= v; i++)
        if(dist[i][i] < min_cycle)
            min_cycle = dist[i][i];
    
    if(min_cycle == INF) printf("-1\n");
    else printf("%d\n", min_cycle);
	
	return 0;
}