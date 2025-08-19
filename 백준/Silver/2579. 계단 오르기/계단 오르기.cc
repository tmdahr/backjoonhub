#include <stdio.h>

int _max(int a,int b)
{
	if(a<b)
		return b;
	return a;
}

int stair[305];
int dp[305];

int main(void)
{
	int last;
	scanf("%d", &last);
	for(int i=1; i<=last; i++) scanf("%d", &stair[i]);
	
	dp[1]=stair[1];
	dp[2]=stair[1]+stair[2];
	dp[3]=_max(stair[1]+stair[3],stair[2]+stair[3]);
	for(int i=4;i<=last;i++)
	{
		dp[i]=_max(dp[i-2]+stair[i],  dp[i-3]+stair[i-1]+stair[i]);
	}
	printf("%d",dp[last]);
	return 0;
}