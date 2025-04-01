#include <stdio.h>
int main(void)
{
	int num[105][105];
	int i, l, j=0, n, m, sn=0, sm=0, max, w=0;
	
	scanf("%d %d", &m, &n);
	max= m*n;
	while(1)
	{
		for(i=sn; i<n; i++)
		{
			w++;
		}
		if(w>=max) break;
		j++;
		sm++;
		
		for(l=sm; l<m; l++)
		{
			w++;
		}
		if(w>=max) break;
		j++;
		n--;
		
		for(i=n; i>sn; i--)
		{
			w++;
		}
		if(w>=max) break;
		j++;
		m--;
		
		for(l=m; l>sm; l--)
		{
			w++;
		}
		if(w>=max) break;
		j++;
		sn++;
	}
	
	printf("%d", j);
	
	return 0;
}