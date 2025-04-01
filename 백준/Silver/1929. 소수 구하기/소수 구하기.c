#include <stdio.h>
int main(void)
{
	int n, m, i, l;
	scanf("%d %d", &m, &n);
	int j[1000001];
	
	for(i=2;i<n;i++)
	{
		if(i>=2)
		{
			if(j[i]==0)
			{
				for(l=2;i*l<=1000000;l++)
				{
					j[i*l]=1;
				}
			}
		}
	}
	j[1]=1;
	for(i=m;i<=n;i++)
	{
			if(i%2!=0||i==2)
			{
				if(j[i]==0)
				{
					printf("%d\n", i);
				}
			}
	}
	return 0;
}