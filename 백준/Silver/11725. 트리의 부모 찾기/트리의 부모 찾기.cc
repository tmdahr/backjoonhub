#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int N;
int parent[100005];
vector<int> map[100005];

void bfs(int v)
{
	queue<int> q;
	q.push(v);
	parent[v]=v;
	
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		
		for(int i=0;i<map[now].size();i++)
		{
			
			int next = map[now][i];
			if(parent[next]==0)
			{
				parent[next]=now;
				q.push(next);	
			}
		}
	}
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N-1;i++)
	{
		int from,to;
		scanf("%d%d",&from,&to);
		map[from].push_back(to);
		map[to].push_back(from);
	}
	
	bfs(1);
	for(int i=2;i<=N;i++)
		printf("%d\n",parent[i]);
	return 0;
}