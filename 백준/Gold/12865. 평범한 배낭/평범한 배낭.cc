#include <stdio.h>
typedef struct _node
{
	int w, v;
} node;
node bag[105];
int dp[105][100005]; //i번째 물건을 선택했을때 최대 j무개일때의 최대값

int main(void)
{
	int n,k;
	scanf("%d %d", &n,&k);
	for(int i=1; i<=n; i++)
	{
		int w,v;
		scanf("%d %d", &w,&v);
		bag[i]={w,v};
	}
	for(int j=1; j<=k; j++)
	{
		for(int i=1; i<=n; i++)
		{
			if(j>=bag[i].w) dp[i][j]=bag[i].v+dp[i-1][j-bag[i].w];
			if(dp[i][j]<dp[i-1][j]) dp[i][j]=dp[i-1][j];
		}
	}
	printf("%d", dp[n][k]);
	return 0;
}