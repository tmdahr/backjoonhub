#include <stdio.h>
int wine[10000];
long long dp[10000];

int _max(long long a, long long b)
{
	if(a>b) return a;
	return b;
}

int main(void)
{
	int n, m=0;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d", &wine[i]);
	dp[1]=wine[1];
	dp[2]=wine[1]+wine[2];
	dp[3]=_max(_max(wine[1]+wine[3],wine[2]+wine[3]),wine[1]+wine[2]);
	
	for(int i=4; i<=n; i++)
	{
		dp[i] = _max(_max(dp[i-2]+wine[i],dp[i-3]+wine[i-1]+wine[i]), dp[i-1]);
	}
		
	printf("%d", dp[n]);
	
	return 0;
}