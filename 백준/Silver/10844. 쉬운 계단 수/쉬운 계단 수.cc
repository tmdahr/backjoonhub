#include <stdio.h>

int main(void)
{
	int n;
	long long dp[102][12];
	dp[1][0]=0;
	for(int i=1; i<=9; i++) dp[1][i]=1;
	scanf("%d", &n);
	for(int i=2; i<=n; i++)
	{
		for(int j=0; j<=9; j++)
		{
			if(j==0) dp[i][j] = dp[i-1][j+1]%1000000000;
			else if(j==9) dp[i][j] = dp[i-1][j-1]%1000000000;
			else dp[i][j] = (dp[i-1][j+1]%1000000000+dp[i-1][j-1]%1000000000)%1000000000;
		}
	}
	long long ans=0;
	for(int i=0; i<=9; i++)
	{
		ans+=dp[n][i];
		ans=ans%1000000000;
	}
	printf("%lld", ans);
	
	return 0;
}