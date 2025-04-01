#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

typedef struct _node
{
	int b;
	long long t;
} node;
int d[1005], indegree[1005], len[1005];
vector<int> rule[1005];
queue<node> build;

int topologic(int n, int w)
{
	for(int i=1; i<=n; i++)
	{
		if(indegree[i]==0) build.push({i,d[i]});
	}
	while(!build.empty())
	{
		node now = build.front();
		build.pop();
		if(now.b==w)
		{
			while(!build.empty()) build.pop();
			return now.t;
		}
		for(int i=0; i<rule[now.b].size(); i++)
		{
			int nb = rule[now.b][i];
			indegree[nb]--;
			if(len[nb]<now.t+d[nb]) len[nb] = now.t+d[nb];
			if(indegree[nb]==0) build.push({nb,len[nb]});
		}
	}
}

int main(void)
{
	int t;
	scanf("%d", &t);
	while(t!=0)
	{
		int n,k,w;
		scanf("%d %d", &n, &k);
		for(int i=1; i<=n; i++)
		{
			scanf("%d", &d[i]);
			indegree[i]=0;
			rule[i].clear();
			len[i]=0;
		}
		for(int i=0; i<k; i++)
		{
			int x,y;
			scanf("%d %d", &x, &y);
			rule[x].push_back(y);
			indegree[y]++;
		}
		scanf("%d", &w);
		long long time = topologic(n,w);
		printf("%d\n", time);
		t--;
	}
	return 0;
}