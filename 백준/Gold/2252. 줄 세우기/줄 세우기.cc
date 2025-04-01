#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
 
vector<int> map[32005];
queue<int> nm;
int indegree[32005];
int n,m;

void topologic()
{
	while(!nm.empty())
	{
		int now = nm.front();
		nm.pop();
		printf("%d ", now);
		for(int i=0;i<map[now].size();i++)
		{
			int num = map[now][i];
			indegree[num]--;
			if(indegree[num]==0)
			{
				nm.push(num);
			}
		}
	}
	
	return;
}

int main(void)
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		map[a].push_back(b);
		indegree[b]++;
	}
	for(int i=1; i<=n; i++)
	{
		if(indegree[i]==0)
		{
			nm.push(i);
		}
	}
	topologic();
	
	return 0;
}