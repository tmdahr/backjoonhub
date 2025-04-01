#include <stdio.h>
int main(void)
{
	int n[1000];
	int i, l, j, m, nm = 0;
	scanf("%d", &m);
	for(i=0; i<m; i++) scanf("%d", &n[i]);
	j = n[0];
	for(i=0; i<m; i++)
	{
		if(n[i] >= n[i+1])
		{
			if(nm < n[i]-j) nm = n[i]-j;
			j = n[i+1];
		}
	}
	printf("%d", nm);
	
	return 0;
}