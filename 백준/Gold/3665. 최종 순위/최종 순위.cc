#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int map[505][505];
int indegree[505], ly[505];
int n,m;

void topologic()
{
	queue<int> rank, ty;
	vector<int> team[505];
	for(int i=1; i<=n; i++)
	{
		if(indegree[i]==0) rank.push(i);
		for(int j=1; j<=n; j++)
		{
			if(map[i][j]==1) team[i].push_back(j); 
		}
	}
	while(!rank.empty())
	{
		int now = rank.front();
		rank.pop();
		ty.push(now);
		for(int i=0; i<team[now].size(); i++)
		{
			int nt = team[now][i];
			indegree[nt]--;
			if(indegree[nt]==0) rank.push(nt);
		}
	}
	if(ty.size()<n) printf("IMPOSSIBLE\n");
	else
	{
		while(!ty.empty())
		{
			printf("%d ", ty.front());
			ty.pop();
		}
		puts("");
	}
	return ;
}

int main(void)
{
	int t;
	scanf("%d", &t);
	while(t!=0)
	{
		scanf("%d", &n);
		for(int i=0; i<=n; i++)
		{
			ly[i]=0;
			for(int j=0; j<=n; j++)
				map[i][j]=0;
		}
		for(int i=1; i<=n; i++)
		{
			int num;
			scanf("%d", &num);
			indegree[num]=i-1;
			ly[num]=i;
			for(int j=1; j<=n; j++)
			{
				if(ly[j]==0) map[num][j]=1;
			}
		}
		scanf("%d", &m);
		if(m==0)
		{
			for(int i=1; i<=n; i++)
				for(int j=1; j<=n; j++)
					if(ly[j]==i) printf("%d ", j);
			puts("");
		}
		else
		{
			for(int i=0; i<m; i++)
			{
				int a,b;
				scanf("%d %d", &a, &b);
				if(map[a][b]==1)
				{
					indegree[a]++;
					indegree[b]--;
					map[a][b]=0;
					map[b][a]=1;
				}
				else
				{
					indegree[a]--;
					indegree[b]++;
					map[a][b]=1;
					map[b][a]=0;
				}
			}
			topologic();
		}
		t--;
	}
	return 0;
}