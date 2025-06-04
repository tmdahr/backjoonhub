#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

typedef struct {
    int num;
    long long t;
} node;

int n, k, w;
int delay[1005], indgree[1005], ct[1005];
vector<int> map[1005];
queue<node> q;

void BFS()
{
	for(int i=1; i<=n; i++)
	{
		if(indgree[i]==0) q.push({i, delay[i]});
	}
	while(!q.empty())
	{
		node now = q.front();
		q.pop();
		if(now.num==w)
		{
			printf("%lld\n", now.t);
			return ;
		}
		for(int i=0; i<map[now.num].size(); i++)
		{
			int next = map[now.num][i];
			indgree[next]--;
			if(ct[next]<now.t+delay[next]) ct[next] = now.t+delay[next];
			if(indgree[next]==0) q.push({next,ct[next]});
		}
	}
}

int main(void)
{
	int t;
	scanf("%d", &t);
	for(; t>0; t--)
	{
		scanf("%d %d", &n, &k);
		while (!q.empty()) q.pop();
		for (int i = 1; i <= n; i++)
		{
    		map[i].clear();
    		indgree[i] = 0;
    		ct[i] = 0;
		}
		for(int i=1; i<=n; i++)
		{
			scanf("%d", &delay[i]);
		}
		int x, y;
		for(int i=0; i<k; i++)
		{
			scanf("%d %d", &x, &y);
			map[x].push_back(y);
			indgree[y]++;
		}
		scanf("%d", &w);
		BFS();
	}
	return 0;
}