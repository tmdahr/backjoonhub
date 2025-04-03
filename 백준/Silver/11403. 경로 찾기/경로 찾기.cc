#include <stdio.h>
#include <queue>
using namespace std;

int N;
int map[105][105];
int ans[105][105];

int solution(int start,int end)
{
	int visit[105]={0};
	queue<int> q;
	q.push(start);
	//visit[start]=1;
	bool flag=false;
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		
		if(now==end && flag==true)
			return 1;
			
		flag = true;
		for(int i=0;i<N;i++)
		{
			if(map[now][i]==1 && visit[i]==0)
			{
				q.push(i);
				visit[i]=1;
			}
		}
	}
	return 0;
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			scanf("%d",&map[i][j]);
			
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			ans[i][j]=solution(i,j);
			
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			printf("%d ",ans[i][j]);	
		printf("\n");
	}
	return 0;
}