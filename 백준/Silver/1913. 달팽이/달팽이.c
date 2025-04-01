#include <stdio.h>
int main(void)
{
	int nn[1005][1005];
	int i, l, j, m, n, p, pi, pl, mi, ml;
	
	scanf("%d", &n);
	scanf("%d", &p);
	
	i=n/2;
	l=n/2;
	j=1;
	nn[i][l]=j;
	m=1;
	mi=i-m;
	ml=l+m;
	if(p==1)
	{
		pi=i;
		pl=l;
	}
	i--;
	while(1)
	{
		for(; i>mi; i--)
		{
			j++;
			nn[i][l]=j;
			if(p==j)
			{
				pi=i;
				pl=l;
			}
		}
		if(j>=n*n) break;
		for(; l<ml; l++)
		{
			j++;
			nn[i][l]=j;
			if(p==j)
			{
				pi=i;
				pl=l;
			}
		}
		m++;
		mi=mi+m;
		ml=ml-m;
		for(; i<mi; i++)
		{
			j++;
			nn[i][l]=j;
			if(p==j)
			{
				pi=i;
				pl=l;
			}
		}
		for(; l>ml; l--)
		{
			j++;
			nn[i][l]=j;
			if(p==j)
			{
				pi=i;
				pl=l;
			}
		}
		m++;
		mi=mi-m;
		ml=ml+m;
	}
	
	for(i=0; i<n; i++)
	{
		for(l=0; l<n; l++)
		{
			printf("%d ", nn[i][l]);
		}
		printf("\n");
	}
	pi++;
	pl++;
	printf("%d %d", pi, pl);
	
	return 0;
}