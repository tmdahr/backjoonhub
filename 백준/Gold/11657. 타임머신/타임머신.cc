#include <stdio.h>
#include <vector>
using namespace std;

typedef struct {
    int from, to, cost;
} node;

vector<long long> dist;
bool cycle = false;

void bellmanFord(int n, vector<node>& edges) {
    dist.resize(n + 1, 2147483647);
    dist[1] = 0;

    for(int i=1; i<=n; i++)
    {
        bool updated = false;
        for(int j=0; j<edges.size(); j++)
        {
            node& edge = edges[j];
            if(dist[edge.from] != 2147483647 && dist[edge.to] > dist[edge.from] + edge.cost)
            {
                if(i == n)
                {
                    cycle = true;
                    return;
                }
                dist[edge.to] = dist[edge.from] + edge.cost;
                updated = true;
            }
        }
        if(!updated) break;
    }
}

int main(void) 
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<node> edges(m);
    for(int i=0; i<m; i++) scanf("%d %d %d", &edges[i].from, &edges[i].to, &edges[i].cost);
    
    bellmanFord(n, edges);
    
    if(cycle) printf("-1\n");
    else
    {
        for(int i = 2; i <= n; i++)
        {
            if(dist[i] == 2147483647) printf("-1\n");
            else printf("%lld\n", dist[i]);
        }
    }
    return 0;
}