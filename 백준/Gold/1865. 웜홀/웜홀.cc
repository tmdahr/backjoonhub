#include <stdio.h>
#include <vector>
using namespace std;

typedef struct
{
	int from, to, cost;
} node;

bool bellmanFord(int n, vector<node>& edges) {
    vector<int> dist(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        bool updated = false;
        for (auto& edge : edges)
		{
            if (dist[edge.to] > dist[edge.from] + edge.cost)
			{
                dist[edge.to] = dist[edge.from] + edge.cost;
                updated = true;
                if (i == n) return true;
            }
        }
        if (!updated) break;
    }
    return false;
}


int main(void)
{
	int tc;
	scanf("%d", &tc);
	while(tc--)
	{
		int n,m,w;
		scanf("%d %d %d", &n, &m, &w);
		vector<node> edges;
		for(int i=0; i<m; i++)
		{
			int s, e, t;
			scanf("%d %d %d", &s, &e, &t);
			edges.push_back({s,e,t});
			edges.push_back({e,s,t});
		}
		for(int i=0; i<w; i++)
		{
			int s, e, t;
			scanf("%d %d %d", &s, &e, &t);
			edges.push_back({s,e,-t});
		}
		if(bellmanFord(n,edges)) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}