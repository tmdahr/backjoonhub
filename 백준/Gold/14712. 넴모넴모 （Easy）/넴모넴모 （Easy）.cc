#include <stdio.h>

int N,M;
int ans;
int map[33][33];

void dfs(int cnt)
{
	if(cnt==N*M)
	{
		ans++;
		return ;
	}
	
	int y = cnt/M +1;
	int x = cnt%M +1;
	
	if(map[y-1][x]==0 || map[y-1][x-1]==0 || map[y][x-1]==0)
	{
		map[y][x]=1;
		dfs(cnt+1);
		map[y][x]=0;
	}
	dfs(cnt+1);
}

int main()
{
	scanf("%d%d",&N,&M);
	
	dfs(0);
	printf("%d",ans);
}