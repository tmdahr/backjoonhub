#include <stdio.h>

int main(void)
{
	int n;
	long long f[1005];
	scanf("%d", &n);
	for(int i=0; i<=n; i++)
	{
		if(i==0||i==1) f[i]=1;
		else f[i]=(f[i-1]+f[i-2])%10007;
		 
	}
	printf("%lld", f[n]);
	
	return 0;
}