#include <stdio.h>
int main(void)
{
	int nn[101]={0};
	int n, m, i, j, l, nm = 0;
	scanf("%d %d",&n,&m);
	for(i=0; i<n; i++)
	{
		scanf("%d",&nn[i]);
	}
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			for(l=0; l<n; l++)
			{
				if(i==j) j++;
				if(i==l) l++;
				if(j==l) l++;
				if( l>=n || j>=n ) break;
				if(nn[i]+nn[j]+nn[l]==m)
				{
					nm=m;
					break;
				}
				else if(nn[i]+nn[j]+nn[l]<m && nn[i]+nn[j]+nn[l]>nm)
				{
					nm=nn[i]+nn[j]+nn[l];
				}
			}
			if(nm==m) break;
		}
		if(nm==m) break;
	}
	printf("%d", nm);
	
	return 0;
}