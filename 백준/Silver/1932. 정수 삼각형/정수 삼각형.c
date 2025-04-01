#include <stdio.h>
int main(void)
{
	int np[502][502];
	int n, i, l, m=0;
	
	scanf("%d", &n);
	scanf("%d", &np[0][0]);
	for(i=1; i<n; i++)
	{
		for(l=0; l<=i; l++)
		{
			scanf("%d", &np[i][l]);
		}
	}
	
	for(i=1; i<n; i++)
	{
		for(l=0; l<=i; l++)
		{
			if(l==0)
			{
				np[i][l]=np[i][l]+np[i-1][l];
			}
			else if(l==i)
			{
				np[i][l]=np[i][l]+np[i-1][l-1];
			}
			else
			{
				if(np[i-1][l]>np[i-1][l-1])
				{
					np[i][l]=np[i][l]+np[i-1][l];
				}
				else
				{
					np[i][l]=np[i][l]+np[i-1][l-1];
				}
			}
		}
	}
	
	i=n-1;
	for(l=0; l<n; l++)
	{
		if(m<np[i][l]) m=np[i][l];
	}
	if(n==1) m = np[0][0];
	printf("%d", m);
	
	return 0;
}