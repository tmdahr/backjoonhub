#include <stdio.h>

int n,m;
int num[10], visit[10];

void back(int stop, int start)
{
	if(stop==m)
	{
		for(int i=0; i<stop; i++) printf("%d ", num[i]);
		printf("\n");
		return;
	}
	for(int i=start; i<=n; i++)
	{
		if(visit[i]==0)
		{
			visit[i]=1;
			num[stop]=i;
			back(stop+1, i);
			visit[i]=0;
		}
	}
}

int main(void)
{
	scanf("%d %d", &n, &m);
	back(0, 1);
}